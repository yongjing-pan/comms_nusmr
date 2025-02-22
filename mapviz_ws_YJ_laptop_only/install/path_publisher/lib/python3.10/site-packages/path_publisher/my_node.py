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
        self.path_publisher = self.create_publisher(Path, 'path', 10)

        # Initialize path message
        self.path = Path()
        self.path.header.frame_id = "map"

        self.MAX_PATH_LENGTH = 100  # Adjust as needed

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
            pose.pose.position.x = msg.latitude - 1.2987358
            pose.pose.position.y = msg.longitude - 103.7715786
            # pose.pose.position.x = 0.0
            # pose.pose.position.y = 0.0

            # Append to path and publish
            self.path.poses.append(pose)

            if len(self.path.poses) > self.MAX_PATH_LENGTH:
                self.path.poses.pop(0)  # Remove the oldest pose

            self.path.header.stamp = self.get_clock().now().to_msg()
            self.path_publisher.publish(self.path)

            self.get_logger().info(f'Updated path with point: ({pose.pose.position.x}, {pose.pose.position.y})')
            self.get_logger().info(f'Time stamp: ({self.path.header.stamp})')
            self.get_logger().info(f'No. of poses: ({len(self.path.poses)})')
            print(self.path.poses)




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
