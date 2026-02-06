import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
import math
import utm  # Install with: pip install utm

class CircleMarkerPublisher(Node):
    def __init__(self):
        super().__init__('circle_marker_publisher')

        # Marker Publisher
        self.marker_publisher = self.create_publisher(Marker, 'marker', 10)
        self.marker_2_publisher = self.create_publisher(Marker, 'marker_2', 10)

        self.dot_marker_publisher = self.create_publisher(Marker, 'dot_marker', 10)
        self.dot_marker_2_publisher = self.create_publisher(Marker, 'dot_marker_2', 10)


        # Define search area parameters
        self.search_radius = 20  # meters
        self.center_lat = 1.2987358   # Example latitude
        self.center_lon = 103.7715786 # Example longitude

         # Define search area parameters
        self.search_radius_2 = 20  # meters
        self.center_lat_2 = 1.298886   # Example latitude
        self.center_lon_2 = 103.771179 # Example longitude
 
     # Define dot coordinates 
        self.dot_lat = 1.298957  # Example latitude
        self.dot_lon = 103.771346  # Example longitude
        self.dot_size = 1.0  # Diameter of the dot in meters

        # Define dot coordinates
        self.dot_lat_2 = 1.299170  # Example latitude
        self.dot_lon_2 = 103.771223 # Example longitude
        self.dot_size_2 = 1.0  # Diameter of the dot in meters


        # Publish the marker at a fixed rate
        self.timer = self.create_timer(1.0, self.publish_marker)

    def generate_circle(self):
        """ Generates a circular marker in UTM coordinates. """
        marker = Marker()
        marker.header.frame_id = "map"  # Make sure it matches Mapviz frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "circle"
        marker.id = 0
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.scale.x = 0.5  # Line thickness
        marker.color.r = 1.0   # Red
        marker.color.a = 1.0   # Fully visible

        # Convert center lat/lon to UTM
        #utm_x, utm_y = 0.0, 0.0
        utm_x, utm_y, _, _ = utm.from_latlon(self.dot_lat_2, self.dot_lon_2)
        default_x, default_y, _, _ = utm.from_latlon(1.2987358, 103.7715786)
        utm_x -= default_x
        utm_y -= default_y


        # Generate circle points
        for angle in range(0, 361, 10):  # Full 360-degree circle
            theta = math.radians(angle)
            point = Point()
            point.x = utm_x + self.search_radius * math.cos(theta)
            point.y = utm_y + self.search_radius * math.sin(theta)
            marker.points.append(point)

        return marker
    
    def generate_circle_2(self):
        """ Generates a circular marker in UTM coordinates. """
        marker = Marker()
        marker.header.frame_id = "map"  # Make sure it matches Mapviz frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "circle"
        marker.id = 0
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.scale.x = 0.5  # Line thickness
        marker.color.r = 1.0   # Red
        marker.color.a = 1.0   # Fully visible

        # Convert center lat/lon to UTM
        #utm_x, utm_y = 0.0, 0.0
        utm_x, utm_y, _, _ = utm.from_latlon(self.dot_lat, self.dot_lon)
        default_x, default_y, _, _ = utm.from_latlon(1.2987358, 103.7715786)
        utm_x -= default_x
        utm_y -= default_y


        # Generate circle points
        for angle in range(0, 361, 10):  # Full 360-degree circle
            theta = math.radians(angle)
            point = Point()
            point.x = utm_x + self.search_radius * math.cos(theta)
            point.y = utm_y + self.search_radius * math.sin(theta)
            marker.points.append(point)

        return marker
    
    def generate_dot(self):
        """ Generates a green dot marker at a specific UTM coordinate. """
        marker = Marker()
        marker.header.frame_id = "map"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "dot"
        marker.id = 1
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.scale.x = self.dot_size  # Sphere diameter (X, Y, Z)
        marker.scale.y = self.dot_size
        marker.scale.z = self.dot_size
        marker.color.g = 1.0   # Green color
        marker.color.r = 1.0
        marker.color.a = 1.0   # Fully visible

        # Convert lat/lon to UTM
        # utm_x, utm_y = 0.0, 0.0
        utm_x, utm_y, _, _ = utm.from_latlon(self.dot_lat, self.dot_lon)
        default_x, default_y, _, _ = utm.from_latlon(1.2987358, 103.7715786)
        utm_x -= default_x
        utm_y -= default_y

        # Set position
        marker.pose.position.x = utm_x 
        marker.pose.position.y = utm_y
        marker.pose.position.z = 0.0  # Keep at ground level

        return marker
    
    def generate_dot_2(self):
        """ Generates a green dot marker at a specific UTM coordinate. """
        marker = Marker()
        marker.header.frame_id = "map"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "dot"
        marker.id = 1
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.scale.x = self.dot_size  # Sphere diameter (X, Y, Z)
        marker.scale.y = self.dot_size
        marker.scale.z = self.dot_size
        marker.color.g = 1.0   # Green color
        marker.color.r = 1.0
        marker.color.a = 1.0   # Fully visible

        # Convert lat/lon to UTM
        # utm_x, utm_y = 0.0, 0.0
        utm_x, utm_y, _, _ = utm.from_latlon(self.dot_lat_2, self.dot_lon_2)
        default_x, default_y, _, _ = utm.from_latlon(1.2987358, 103.7715786)
        utm_x -= default_x
        utm_y -= default_y


        # Set position
        marker.pose.position.x = utm_x 
        marker.pose.position.y = utm_y
        marker.pose.position.z = 0.0  # Keep at ground level

        return marker
    def publish_marker(self):
        """ Publishes the generated circular marker """
        marker = self.generate_circle()
        marker_2 = self.generate_circle_2()
        dot_marker = self.generate_dot()
        dot_marker_2 = self.generate_dot_2()

        self.marker_publisher.publish(marker)
        self.marker_2_publisher.publish(marker_2)

        self.dot_marker_publisher.publish(dot_marker)
        self.dot_marker_2_publisher.publish(dot_marker_2)

        self.get_logger().info("Published search area marker")

def main(args=None):
    rclpy.init(args=args)
    node = CircleMarkerPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
