#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

class AddMarkers {
private:
	
	// initialise ros
    ros::NodeHandle n;
    ros::Subscriber odom_sub;
    ros::Publisher marker_pub;
    visualization_msgs::Marker marker;

    // setup parameters
    double pickup[2] = {3.53, 3.10};
    double dropoff[2] = {-1.00, 0.00};

public:

	AddMarkers(){

		// subscriber
		odom_sub = n.subscribe("/odom", 1, &AddMarkers::odomCallback, this);

		// publisher
        marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

        // initialize marker and show marker at pickup zone
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "add_markers";
        marker.id = 0;
        marker.type = visualization_msgs::Marker::CUBE;
        marker.action = visualization_msgs::Marker::ADD;
        marker.scale.x = 0.50;
        marker.scale.y = 0.50;
        marker.scale.z = 0.50;
        marker.color.r = 0.0f;
        marker.color.g = 0.0f;
        marker.color.b = 1.0f;
        marker.color.a = 1.0;
        marker.pose.position.x = pickup[0];
        marker.pose.position.y = pickup[1];
        marker.pose.position.z = 0.10;
        marker.lifetime = ros::Duration();
        publishMarker();

	}


    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {

    	// calculate euclidean distances
        float pickup_dst = sqrt(pow((pickup[0] - msg->pose.pose.position.x), 2) + pow((pickup[1] - msg->pose.pose.position.y), 2));
        float dropoff_dst = sqrt(pow((dropoff[0] - msg->pose.pose.position.x), 2) + pow((dropoff[1] - msg->pose.pose.position.y), 2));
 
 		// simple approach - improvement needed for more than 2 locations...
        if (pickup_dst <= 0.65) // @ pickup
        {
        	ros::Duration(5).sleep();
	        marker.pose.position.x = dropoff[0];
        	marker.pose.position.y = dropoff[1];
        	marker.pose.position.z = 0.10;
        	marker.color.a = 0.0;
        	publishMarker(); // publish dropoff marker
        	ROS_INFO("Arrived at pickup location...");
        }
        else if (dropoff_dst <= 0.28) // @ dropoff
        {
        	marker.color.a = 1.0;
        	publishMarker(); // publish dropoff marker
        	ROS_INFO("Arrived at dropoff location...");
        }
           
    }


    void publishMarker() 
    {
        
        // check subscribed once
        while (marker_pub.getNumSubscribers() < 1) {
            ROS_WARN_ONCE("Waiting for subscription...");
            sleep(1);
        }

        // publish
        marker_pub.publish(marker);
    }


};

int main(int argc, char **argv) {
    ros::init(argc, argv, "add_markers_node");

    AddMarkers addMarkers;
    ros::spin();

    return 0;
}