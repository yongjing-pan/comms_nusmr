from setuptools import find_packages, setup

package_name = 'path_publisher'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yongjing-ub22',
    maintainer_email='yongjing.pan03@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'my_node = path_publisher.my_node:main',
            'draw_circle = path_publisher.draw_circle:main'
        ],
    },
)
