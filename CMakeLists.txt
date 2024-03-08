# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("carCrashAvoidanceSystemSimulation")

# Include sub-projects.
#add_subdirectory ("carCrashAvoidanceSystemSimulation")

add_executable(draftTwo
        main.cpp
        sensor-GPS.h
        sensor-GPS.cpp
        sensor-ULTRASONIC.h
        sensor-ULTRASONIC.cpp
        Controller.h
        Controller.cpp
        Model.h
        Model.cpp
        View.h
        View.cpp
        color.hpp
        sensor-BREAK.h
        sensor-BREAK.cpp
        Authentication.h
        Authentication.cpp
        Authenticator.h
        Authenticator.cpp
        Subject.h
        Subject.cpp
        ProofOfID.h
        ProofOfID.cpp
        Permission.h
        Permission.cpp
        PermissionType.h
        Resource.h
        Resource.cpp
        Role.h
        Role.cpp
        secureData.h
        secureData.cpp
        SensorData.h
        SensorData.cpp
        userInput.h
        userInput.cpp
        displayMenu.h
        displayMenu.cpp
        displayWarnings.h
        displayWarnings.cpp
        displayVehicleData.h
        displayVehicleData.cpp
        displayUserData.h
        displayUserData.cpp
        displaySensorData.h
        displaySensorData.cpp
        inputValidation.h
        inputValidation.cpp
        loggSensorData.h
        loggSensorData.cpp
        sensor-SPEED.h
        sensor-SPEEd.cpp)

# Set linker flags
add_link_options(/DYNAMICBASE /NXCOMPAT /SAFESEH)