set(Botan_DIR "C:/Botan/lib/cmake/Botan-3.8.0")

find_package(Botan 3.8.0 CONFIG REQUIRED)

add_executable(
    SMA 

	src/main.cpp
    src/network/crc32.h 
    src/crypt/crypt.h src/crypt/crypt.cpp
    src/core/app.h 
     
    src/update/serverlist.h src/update/serverlist.cpp
    src/core/server.h src/core/server.cpp
    src/core/logger.h src/core/logger.cpp
    src/core/client.h src/core/client.cpp
    src/network/protocol.h src/network/protocol.cpp
     
    src/network/transportprotocol.h src/network/transportprotocol.cpp
    src/network/udptransport.h src/network/udptransport.cpp
    src/network/tcptransport.h src/network/tcptransport.cpp
    src/core/profile.h src/core/profile.cpp
    src/core/filelogger.h src/core/filelogger.cpp
    src/core/streamlogger.h src/core/streamlogger.cpp
)

target_link_libraries(SMA PRIVATE Botan::Botan)
target_link_libraries(SMA PRIVATE ws2_32)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SMA PROPERTY CXX_STANDARD 20)
endif()
