set(ENV{PATH} "C:/vcpkg/installed/x64-windows/debug/bin;$ENV{PATH}")
set(botan_DIR "C:/vcpkg/installed/x64-windows/share/botan")

find_package(botan CONFIG REQUIRED)

add_executable(
    SMA 

	src/main.cpp
    src/network/crc32.h 
    src/crypt/crypt.h src/crypt/crypt.cpp
    src/core/app.h src/core/app.cpp
     
    src/gui/gui.h src/gui/gui.cpp
    src/update/serverlist.h src/update/serverlist.cpp
    src/core/server.h src/core/server.cpp
    src/core/logger.h src/core/logger.cpp
    src/core/client.h src/core/client.cpp
    src/network/protocol.h src/network/protocol.cpp
     
    src/core/profile.h src/core/profile.cpp
    src/network/transportprotocol.h src/network/transportprotocol.cpp
    src/network/udptransport.h src/network/udptransport.cpp
    src/network/tcptransport.h src/network/tcptransport.cpp
     
)

target_link_libraries(SMA PRIVATE Botan::Botan)

add_custom_command(
    TARGET SMA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "C:/vcpkg/installed/x64-windows/debug/bin"
    "$<TARGET_FILE_DIR:SMA>"
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SMA PROPERTY CXX_STANDARD 20)
endif()
