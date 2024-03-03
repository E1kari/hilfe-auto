cmake_minimum_required(VERSION 3.24)

include(../cmake/raylib.cmake)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp
        Würfelspiel/Dices/BaseDice.cpp
        Würfelspiel/Dices/BaseDice.h
        Würfelspiel/Würfelspiel.cpp
        Würfelspiel/Würfelspiel.h
        Würfelspiel/UI.cpp
        Würfelspiel/UI.h
        Würfelspiel/PlayRound.cpp
        Würfelspiel/PlayRound.h
        Würfelspiel/Dices/D6.cpp
        Würfelspiel/Dices/D6.h
        Würfelspiel/Dices/D8.cpp
        Würfelspiel/Dices/D8.h
        Würfelspiel/Dices/D10.cpp
        Würfelspiel/Dices/D10.h
        Würfelspiel/Dices/D10p.cpp
        Würfelspiel/Dices/D10p.h
        Würfelspiel/Dices/D12.cpp
        Würfelspiel/Dices/D12.h
        Würfelspiel/Dices/D20.cpp
        Würfelspiel/Dices/D20.h
        Sprite/Sprite.cpp
        Sprite/Sprite.h
        Sprite/Frame.cpp
        Sprite/Frame.h
        Raylib_Sprite_Klasse/Sprite.cpp
        Raylib_Sprite_Klasse/Sprite.h
        Eine_Level_Klasse/Level.cpp
        Eine_Level_Klasse/Level.h
        Eine_Level_Klasse/Eine_Level_Klasse.cpp
        Eine_Level_Klasse/Eine_Level_Klasse.h
        Auto/BaseCar.cpp
        Auto/BaseCar.h
        Auto/components/BaseWheels.cpp
        Auto/components/BaseWheels.h
        Auto/components/BaseGears.cpp
        Auto/components/BaseGears.h
        Auto/components/BaseEngine.cpp
        Auto/components/BaseEngine.h
        Auto/components/BaseBreak.cpp
        Auto/components/BaseBreak.h
        Auto/components/BaseFrame.cpp
        Auto/components/BaseFrame.h
        Auto/components/BaseSuspension.cpp
        Auto/components/BaseSuspension.h
        Auto/Car1.cpp
        Auto/Car1.h
        Auto/Car2.cpp
        Auto/Car2.h
)

# Add config.h.in file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

# Link to Raylib
# Static linking may be interesting, especially under Windows with MinGW,
# so that the MinGW DLLs do not have to be supplied.
# (Unfortunately, there is no easy way to link the C++ standard libraries
# statically and other libraries dynamically.)
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    target_link_libraries(${PROJECT_NAME} raylib)
else()
    target_link_libraries(${PROJECT_NAME} raylib -static)
endif()

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")