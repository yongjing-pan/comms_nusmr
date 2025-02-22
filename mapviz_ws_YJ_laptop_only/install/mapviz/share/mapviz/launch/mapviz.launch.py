import launch
import launch.actions
import launch.substitutions
import launch_ros.actions

'''
 "latitude": 1.2987358,
                        "longitude": 103.7715786,
                        "altitude": 102.26,
'''


def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package="mapviz",
            executable="mapviz",
            name="mapviz",
        ),
        launch_ros.actions.Node(
            package="swri_transform_util",
            executable="initialize_origin.py",
            name="initialize_origin",
            parameters=[
                {"local_xy_frame": "map"},
                {"local_xy_origin": "swri"},
                {"local_xy_origins": """[
                    {"name": "swri",
                        "latitude": 0.0,
                        "longitude": 0.0,
                        "altitude": 0.0,
                        "heading": 0.0},
                    {"name": "back_40",
                        "latitude": 29.447507,
                        "longitude": -98.629367,
                        "altitude": 200.0,
                        "heading": 0.0}
                ]"""},
            ]
        ),
        launch_ros.actions.Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="swri_transform",
            arguments=["0", "0", "0", "0", "0", "0", "map", "origin"]
        )
    ])
