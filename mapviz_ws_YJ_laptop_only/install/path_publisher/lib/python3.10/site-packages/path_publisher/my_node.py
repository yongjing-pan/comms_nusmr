import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped
import utm  # Install using: pip install utm

class GNSSPathPublisher(Node):
    def __init__(self):
        super().__init__('gnss_path_publisher')
        
        # Subscriber to GNSS data
        self.subscription = self.create_subscription(
            NavSatFix, 
            'gps/fix',  # Change if using a different GNSS topic
            self.callback, 
            10
        )
        
        # Publisher for the path
        self.path_publisher = self.create_publisher(Path, 'gnss_path', 10)

        # Initialize path message
        self.path = Path()
        self.path.header.frame_id = "map"

    def callback(self, msg):
        """ Callback function to update and publish path """
        try:
            # Convert lat/lon to UTM coordinates
            utm_x, utm_y, _, _ = utm.from_latlon(msg.latitude, msg.longitude)
            print(f"Latitude: {msg.latitude}")

            pose = PoseStamped()
            pose.header.stamp = msg.header.stamp
            pose.header.frame_id = "map"

            # Store UTM values in Pose
            pose.pose.position.x = utm_x
            pose.pose.position.y = utm_y

            # Append to path and publish
            self.path.poses.append(pose)
            self.path.header.stamp = self.get_clock().now().to_msg()
            self.path_publisher.publish(self.path)

            self.get_logger().info(f'Updated path with point: ({utm_x}, {utm_y})')

        except Exception as e:
            self.get_logger().error(f"Error converting GNSS data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = GNSSPathPublisher()
    rclpy.spin(node)
    print("node starting now")
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
