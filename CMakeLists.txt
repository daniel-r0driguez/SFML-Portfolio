cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME Portfolio_Project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Runnable.h SFMLObject.h MouseEvents.h MouseEvents.cpp Thumbnail.cpp Thumbnail.h
        ../GreenCircleProject/Application.h GreenCricleProject/GreenCircle.h GreenCricleProject/GreenCircle.cpp
        GreenCricleProject/GreenCircleApplication.cpp GreenCricleProject/GreenCircleApplication.h PortfolioApplication.cpp
        PortfolioApplication.h Position.h Position.cpp PhaserProject/PhaserAnimatedSprite.h PhaserProject/PhaserAnimatedSprite.cpp
        PhaserProject/PhaserApplication.cpp BouncingBallProject/BouncingBallApplication.h BouncingBallProject/BouncingBallApplication.cpp
        BouncingBallProject/Ball.cpp SFML_2D_ARRAY_PROJECT/Grid.cpp SFML_2D_ARRAY_PROJECT/SFMLGrid.cpp SFML_2D_ARRAY_PROJECT/sfml2DArrayApplication.cpp
        SFML_2D_ARRAY_PROJECT/sfml2DArrayApplication.h PlayingCardProject/PlayingCardApplication.cpp PlayingCardProject/PlayingCardApplication.h PlayingCardProject/Background.cpp
        PlayingCardProject/CardSFML.cpp PlayingCardProject/Font.cpp PlayingCardProject/Rank.cpp PlayingCardProject/Suit.cpp PlayingCardProject/Images.cpp PokerAnalysisProject/PokerAnalysisApplication.cpp
        PokerAnalysisProject/CardHandScorer.cpp PokerAnalysisProject/CardHandSFML.cpp PokerAnalysisProject/ConsoleCard.cpp PokerAnalysisProject/ConsoleCardHand.cpp
        PokerAnalysisProject/ConsoleDeck.cpp PokerAnalysisProject/PokerScore.cpp PokerAnalysisProject/SetHand.cpp PokerAnalysisProject/SimulatePokerRounds.cpp
        PokerAnalysisProject/TextBox.cpp FinalGameProject/AnimatedSpriteComponent.cpp FinalGameProject/FinalGameApplication.cpp FinalGameProject/Bitmask.cpp FinalGameProject/CameraComponent.cpp FinalGameProject/Chunk.cpp FinalGameProject/CollisionDetector.cpp FinalGameProject/DamageComponent.cpp FinalGameProject/Enemy.cpp FinalGameProject/Goomba.cpp FinalGameProject/HealthComponent.cpp FinalGameProject/HitboxComponent.cpp FinalGameProject/FinalGameImages.cpp FinalGameProject/InputComponent.cpp FinalGameProject/Koopa.cpp FinalGameProject/MovementComponent.cpp FinalGameProject/MusicManager.cpp FinalGameProject/PhysicsComponent.cpp FinalGameProject/Player.cpp FinalGameProject/pugixml.cpp FinalGameProject/Solid.cpp FinalGameProject/SoundManager.cpp FinalGameProject/TiledMap.cpp FinalGameProject/TiledMapReader.cpp FinalGameProject/TransformComponent.cpp FinalGameProject/FinalGameImages.h PortfolioImages.cpp PortfolioImages.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)



set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()