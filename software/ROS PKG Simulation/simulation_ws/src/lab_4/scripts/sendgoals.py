#!/usr/bin/env python3

import rospy
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
import actionlib
from std_msgs.msg import String

def main():
    # Initialize ROS node
    rospy.init_node('simple_navigation_goals')

    # Create an action client for move_base
    ac = actionlib.SimpleActionClient('move_base', MoveBaseAction)
    ac.wait_for_server()

    # User choice and loop control variables
    user_choice = 6
    choice_to_continue = 'Y'
    run = True

    while run:
        # Ask the user where they want the robot to go
        print("\nWhere do you want the robot to go?")
        print("\n1 = Bathroom")
        print("2 = Bedroom")
        print("3 = Front Door")
        print("4 = Living Room")
        print("5 = Home Office")
        print("6 = Kitchen")
        user_choice = int(input("\nEnter a number: "))

        # Create a new goal to send to move_base
        goal = MoveBaseGoal()

        # Send a goal to the robot
        goal.target_pose.header.frame_id = "map"
        goal.target_pose.header.stamp = rospy.Time.now()

        # Set the goal location based on user choice
        if user_choice == 1:
            print("\nGoal Location: Bathroom\n")
            goal.target_pose.pose.position.x =5.071180466504143

            goal.target_pose.pose.position.y = 3.209684426418992

        elif user_choice == 2:
            print("\nGoal Location: Bedroom\n")
            goal.target_pose.pose.position.x = 8.1
            goal.target_pose.pose.position.y = 4.3
        elif user_choice == 3:
            print("\nGoal Location: Front Door\n")
            goal.target_pose.pose.position.x = 10.5
            goal.target_pose.pose.position.y = 2.0
        elif user_choice == 4:
            print("\nGoal Location: Living Room\n")
            goal.target_pose.pose.position.x = 5.3
            goal.target_pose.pose.position.y = 2.7
        elif user_choice == 5:
            print("\nGoal Location: Home Office\n")
            goal.target_pose.pose.position.x = 2.5
            goal.target_pose.pose.position.y = 2.0
        elif user_choice == 6:
            print("\nGoal Location: Kitchen\n")
            goal.target_pose.pose.position.x = 3.0
            goal.target_pose.pose.position.y = 6.0
        else:
            print("\nInvalid selection. Please try again.\n")
            continue

        goal.target_pose.pose.orientation.w = 1.0

        # Send the goal
        print("Sending goal")
        ac.send_goal(goal)

        # Wait until the robot reaches the goal
        ac.wait_for_result()

        # Check if the robot succeeded or failed to reach the goal
        if ac.get_state() == actionlib.GoalStatus.SUCCEEDED:
            print("The robot has arrived at the goal location")
        else:
            print("The robot failed to reach the goal location for some reason")

        # Ask the user if they want to continue
        choice_to_continue = input("\nWould you like to go to another destination? (Y/N)").strip().lower()

        if choice_to_continue != 'y':
            run = False

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass

