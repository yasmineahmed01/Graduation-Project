#!/usr/bin/env python3

import rospy
import subprocess

def main():
    rospy.init_node('launch_inside_node', anonymous=True)
    rospy.loginfo("Launching robot_amcl.launch")
    
    # Run the roslaunch command
    subprocess.call(["roslaunch", "lab_4", "robot_amcl.launch"])
    
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass

