#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/pipeso"

int main()
{
  int server, length;
  struct sockaddr_un remote;
  char buffer[1024];

  // Create socket
  server = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server < 0)
  {
    perror("Create socket failed!");
    return 1;
  }

  // Connect to server
  memset(&remote, 0, sizeof(remote));
  remote.sun_family = AF_UNIX;
  strncpy(remote.sun_path, SOCKET_PATH, sizeof(remote.sun_path) - 1);
  length = strlen(remote.sun_path) + sizeof(remote.sun_family);
  if (connect(server, (struct sockaddr *)&remote, length) < 0)
  {
    perror("Connect server failed!");
    close(server);
    return 1;
  }

  printf("Server connected!\n");

  // Send data to server
  printf("Enter data to be sent: ");
  fgets(buffer, sizeof(buffer), stdin);
  if (write(server, buffer, strlen(buffer) + 1) < 0)
  {
    perror("Write socket failed!");
    close(server);
    return 1;
  }

  printf("Data sent from server.\n");

  // Read data from server
  if (read(server, buffer, sizeof(buffer)) < 0)
  {
    perror("Read socket data failed!");
    close(server);
    return 1;
  }

  printf("Received data: %s\n", buffer);

  // Close socket and exit
  close(server);
  return 0;
}