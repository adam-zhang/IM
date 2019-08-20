cmake_minimum_required(VERSION 2.8)
project(db)
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-D BOOST_LOG_DYN_LINK=1)
set(sources main.cpp
	Database.cpp
	#sqlite3/sqlite3.c
	)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} 
	boost_log 
	dl 
	pthread 
	stdc++fs 
	sqlite3cc.a 
	sqlite3
	)
