/*
 * File:          controle_robo.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */

int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  //instanciando motores
  WbDeviceTag left_motor_1 = wb_robot_get_device("front left wheel");
  WbDeviceTag right_motor_1 = wb_robot_get_device("front right wheel");
  WbDeviceTag left_motor_2 = wb_robot_get_device("back left wheel");
  WbDeviceTag right_motor_2 = wb_robot_get_device("back right wheel");
  //instanciando todos  sensores da frente
  WbDeviceTag sensf1 = wb_robot_get_device("so1");
  WbDeviceTag sensf2 = wb_robot_get_device("so2");
  WbDeviceTag sensf4 = wb_robot_get_device("so4");
  WbDeviceTag sensf6 = wb_robot_get_device("so6");
  WbDeviceTag sensf0 = wb_robot_get_device("so0");
  WbDeviceTag sensf7 = wb_robot_get_device("so7");
  WbDeviceTag sensf3 = wb_robot_get_device("so3");
  WbDeviceTag sensf5 = wb_robot_get_device("so5");
  
  //aplicando o tempo em passos que os sensores vão caputar sinais
  wb_distance_sensor_enable(sensf1,TIME_STEP);
  wb_distance_sensor_enable(sensf2,TIME_STEP);
  wb_distance_sensor_enable(sensf4,TIME_STEP);
  wb_distance_sensor_enable(sensf6,TIME_STEP);
  wb_distance_sensor_enable(sensf0,TIME_STEP);
  wb_distance_sensor_enable(sensf7,TIME_STEP);
  wb_distance_sensor_enable(sensf3,TIME_STEP);
  wb_distance_sensor_enable(sensf5,TIME_STEP);
  
  
  //setando posição do motor
  wb_motor_set_position(left_motor_1,INFINITY);
  wb_motor_set_position(right_motor_1,INFINITY);
  wb_motor_set_position(left_motor_2,INFINITY);
  wb_motor_set_position(right_motor_2,INFINITY);
  
  //velocidade dos motores nas 4 rodas
  double left_speed_1 = 5.0;
  double left_speed_2 = 5.0;
  double right_speed_1=5.0;
  double right_speed_2=5.0;
  
  //variaveis que vão pegar os valores dos sensores
  double sensf2_value;
  double sensf4_value;
  double sensf6_value;
  double sensf0_value;
  double sensf7_value;
  double sensf3_value;
  double sensf5_value;
  double sensf1_value; 
  
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
  
     //pegando os valores dos sensores
     sensf1_value = wb_distance_sensor_get_value(sensf1);
     sensf2_value = wb_distance_sensor_get_value(sensf2);
     sensf4_value = wb_distance_sensor_get_value(sensf4);
     sensf6_value = wb_distance_sensor_get_value(sensf6);
     sensf0_value = wb_distance_sensor_get_value(sensf0);
     sensf7_value = wb_distance_sensor_get_value(sensf7);
     sensf3_value = wb_distance_sensor_get_value(sensf3);
     sensf5_value = wb_distance_sensor_get_value(sensf5);
     
     
    // printf("sensor f %f sensor b %f\n",sensf2_value,sensf4_value);
     //fflush(stdout);
      //esse if verifica se um sensor identificou um objeto,tal que se o valor for maior que 900, por exemplo, o carro vira 
     if(sensf2_value >= 900 || sensf4_value >= 900 || sensf6_value >= 900 || sensf0_value >= 990 ||
      sensf7_value >= 990 || sensf3_value >= 900 || sensf5_value >= 900 || sensf1_value >= 900){
     
        //aqui o carro vira para a esquerda até nenhum sensor captar um sinal menor que 900
        left_speed_1 = -5.0;
        left_speed_2 = -5.0;
        right_speed_1= 5.0;
        right_speed_2= 5.0;    
     
     }
     //caso nenhum sensor acuse os valores anteriores, o carro anda reto
     else{
     
        left_speed_1 = 5.0;
        left_speed_2 = 5.0;
        right_speed_1= 5.0;
        right_speed_2= 5.0; 
     
     }
     
         
     //aqui seta a velocidade dos motores
     wb_motor_set_velocity(left_motor_1,left_speed_1);
     wb_motor_set_velocity(left_motor_2,left_speed_2);
     wb_motor_set_velocity(right_motor_1,right_speed_1);
     wb_motor_set_velocity(right_motor_2,right_speed_2);
  
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
