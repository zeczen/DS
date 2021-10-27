cmake_minimum_required(VERSION 3.20)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories("Medical System/Medical System")

add_executable(DS "Medical System/Medical System/HashInt.cpp"
        "Medical System/Medical System/HashInt.h" "Medical System/Medical System/Item.h"
        "Medical System/Medical System/Prime.cpp" "Medical System/Medical System/Prime.h"
        "Medical System/Medical System/taskRun2.cpp" "Medical System/Medical System/Volunteer.h" "Medical System/Medical System/HashVolunteer.h" "Medical System/Medical System/HashVolunteer.cpp" "Medical System/Medical System/Client.h" "Medical System/Medical System/HashClient.h" "Medical System/Medical System/HashClient.cpp" "Medical System/Medical System/Stock.cpp" "Medical System/Medical System/Stock.h")