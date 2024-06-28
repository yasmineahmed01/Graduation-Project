#!/usr/bin/env python3

import rospy
import subprocess
from std_msgs.msg import String
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
import actionlib
import signal
import sys

# Function to send a navigation goal to the robot
def send_goal(x, y):
    # Create an action client to communicate with the move_base action server
    ac = actionlib.SimpleActionClient('move_base', MoveBaseAction)
    ac.wait_for_server()  # Wait for the action server to be available

    # Create a goal to send to the move_base server
    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"  # Use the "map" coordinate frame
    goal.target_pose.header.stamp = rospy.Time.now()  # Set the current time

    # Set the goal position and orientation
    goal.target_pose.pose.position.x = x
    goal.target_pose.pose.position.y = y
    goal.target_pose.pose.orientation.w = 1.0  # Facing forward

    rospy.loginfo(f"Sending goal to x: {x}, y: {y}")
    ac.send_goal(goal)  # Send the goal to the action server
    ac.wait_for_result()  # Wait for the action server to process the goal

    # Check the result of the goal
    if ac.get_state() == actionlib.GoalStatus.SUCCEEDED:
        rospy.loginfo("The robot has arrived at the goal location")
    else:
        rospy.loginfo("The robot failed to reach the goal location")

# Function to handle navigation to different rooms
def handle_room_navigation(room_number):
    rospy.loginfo(f"Launching robot_amcl for room {room_number}")
    subprocess.Popen(["roslaunch", "lab_4", "robot_amcl.launch"])  # Launch robot_amcl.launch
    rospy.sleep(5)  # Allow some time for the launch file to start

    # Navigate to the specific room based on the room number
    if room_number == 1:
        rospy.loginfo("Navigating to Room 1")
        send_goal(5.071180466504143, 3.209684426418992)  # Coordinates for Room 1
    elif room_number == 2:
        rospy.loginfo("Navigating to Room 2")
        send_goal(8.1, 4.3)  # Coordinates for Room 2
    elif room_number == 3:
        rospy.loginfo("Navigating to Room 3")
        send_goal(10.5, 2.0)  # Coordinates for Room 3
    elif room_number == 4:
        rospy.loginfo("Navigating to Room 4")
        send_goal(5.3, 2.7)  # Coordinates for Room 4
    elif room_number == 5:
        rospy.loginfo("Navigating to Room 5")
        send_goal(2.5, 2.0)  # Coordinates for Room 5
    elif room_number == 6:
        rospy.loginfo("Navigating to Room 6")
        send_goal(3.0, 6.0)  # Coordinates for Room 6
    else:
        rospy.loginfo(f"Room {room_number} is not recognized")

# Callback function for the subscriber to process incoming messages
def callback(msg):
    rospy.loginfo("Received message: %s", msg.data)
    if msg.data == "automatic":
        # If the message is "automatic", run the spi_auto node
        rospy.loginfo("Running spi_auto node")
        subprocess.Popen(["rosrun", "lab_4", "spi_auto"])
    elif msg.data.startswith("room"):
        try:
            #subprocess.Popen(["rviz"])  
            room_number = int(msg.data[4:])  # Extract the room number from the message
            handle_room_navigation(room_number)  # Handle navigation to the specified room
        except ValueError:
            rospy.loginfo("Received room message with invalid number")
    elif msg.data == "terminate":
        rospy.loginfo("Termination requested")
        # Call the signal handler directly
        subprocess.Popen(["pkill", "rviz"])  # Terminate RViz
    else:
        rospy.loginfo("Received message is not recognized: %s", msg.data)

# Signal handler function
def signal_handler(sig, frame):
    rospy.loginfo("Ctrl+C captured, exiting...")
    rospy.signal_shutdown("Ctrl+C received")
    sys.exit(0)

# Function to initialize the ROS node and set up the subscriber
def listener():
    rospy.init_node('app_topic_subscriber', anonymous=True)  # Initialize the ROS node
    rospy.Subscriber('/app_topic', String, callback)  # Subscribe to the /app_topic
    rospy.spin()  # Keep the node running and processing callbacks

if __name__ == '__main__':
    # Register the signal handler
    signal.signal(signal.SIGINT, signal_handler)
    listener()  # Run the listener function if the script is executed

