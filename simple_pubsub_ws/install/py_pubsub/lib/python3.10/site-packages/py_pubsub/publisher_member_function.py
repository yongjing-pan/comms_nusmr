# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix 
from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped
import utm  # Install using: pip install utm


from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher') 

        print("Initialising subscriber")
        self.subscription = self.create_subscription(
            NavSatFix,
            '/gps/fix',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.latitude = 0

        # Publisher for the path
        self.path_publisher = self.create_publisher(Path, 'path', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

        # Initialize path message
        self.path = Path()
        self.path.header.frame_id = "map"


    def timer_callback(self):
        msg = String()
        msg.data = 'Hello dave: %d' % self.i
        # self.publisher_.publish(msg)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
        # self.i += 1
    
    def listener_callback(self, msg):
        self.get_logger().info('Latitude: "%s"' % msg.latitude)
        self.latitude = msg.latitude

        print("Trying to update path...")
        """ Callback function to update and publish path """
        try:
            # Convert lat/lon to UTM coordinates
            # utm_x, utm_y, _, _ = utm.from_latlon(msg.latitude, msg.longitude)
            print(f"Latitude: {msg.latitude}")

            pose = PoseStamped()
            pose.header.stamp = msg.header.stamp
            pose.header.frame_id = "map"

            # Store UTM values in Pose
            pose.pose.position.x = msg.latitude
            pose.pose.position.y = msg.longitude

            # Append to path and publish
            self.path.poses.append(pose)
            self.path.header.stamp = self.get_clock().now().to_msg()
            self.path_publisher.publish(self.path)
            self.i += 1

            self.get_logger().info(f'Updated path with point: ({msg.latitude}, {msg.longitude})')

        except Exception as e:
            self.get_logger().error(f"Error converting GNSS data: {e}")


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node() 
    rclpy.shutdown()


if __name__ == '__main__':
    main()
