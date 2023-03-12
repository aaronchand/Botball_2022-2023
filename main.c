#include <kipr/wombat.h>

void spin_right(int degrees);
int main()
{
    //connect to the robot
    create_connect();
    
    //stop moving in 118 seconds
    shut_down_in(118);
    
    //drive to center
    set_create_distance(0);
    while(get_create_distance() > -250)
    {
      create_drive_direct(-200,-200);
        msleep(15);
    }
    	create_stop();
    
    //spin right towards poms
    spin_right(100);
    	create_stop();
    
    //drive to collect poms
    set_create_distance(0);
    while(get_create_distance() > -2000)
    {
      create_drive_direct(-198,-200);
        msleep(15);
    }
    	create_stop();
    
    //spin right towards the Cybersecurity Lab
    spin_right(90);
    	create_stop();
    
    //drive to push poms into Cybersecurity Lab
    set_create_distance(0);
    while(get_create_distance() > -200)
    {
      create_drive_direct(-200,-200);
        msleep(15);
    }
    	create_stop();
    
    //drive out of Cybersecurity Lab
    set_create_distance(0);
    while(get_create_distance() < 200)
    {
      create_drive_direct(200,200);
        msleep(15);
    }
    create_stop();
    
    //diconnect from the robot
    create_disconnect();
    return 0;
}

void spin_right(int degrees)
{
    int target_angle;
    target_angle = get_create_total_angle() - degrees;
    while(get_create_total_angle() > target_angle)
    {
     create_drive_direct(200,-200);   
    }
    create_stop();
}