cmake_minimum_required(VERSION 2.8.3)
project(spider_bot)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  message_generation
)


## Generate services in the 'srv' folder
add_service_files(
  FILES
  move.srv
)


generate_messages(
  DEPENDENCIES
   geometry_msgs
)


catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
${catkin_INCLUDE_DIRS}
)

add_executable(server src/server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server spider_bot_generate_messages_cpp)

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client spider_bot_generate_messages_cpp)
