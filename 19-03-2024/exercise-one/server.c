#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <ctype.h>

#define SOCKET_PATH "/tmp/pipeso"

int main()
{
  int server, client, length;
  struct sockaddr_un local, remote;
  char buffer[1024];

  // Create socket
  server = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server < 0)
  {
    perror("Create pipe failed!");
    return 1;
  }

  // Bind socket to local address
  memset(&local, 0, sizeof(local));
  local.sun_family = AF_UNIX;
  strncpy(local.sun_path, SOCKET_PATH, sizeof(local.sun_path) - 1);
  unlink(local.sun_path);
  length = strlen(local.sun_path) + sizeof(local.sun_family);
  if (bind(server, (struct sockaddr *)&local, length) < 0)
  {
    perror("Capture socket failed!");
    close(server);
    return 1;
  }

  if (listen(server, 5) < 0)
  {
    perror("Listen server failed!");
    close(server);
    return 1;
  }

  printf("Named pipe server listening in %s...\n", SOCKET_PATH);

  // Accept connections
  memset(&remote, 0, sizeof(remote));
  length = sizeof(remote);
  client = accept(server, (struct sockaddr *)&remote, &length);
  if (client < 0)
  {
    perror("Accept connection failed!");
    close(server);
    return 1;
  }

  printf("Client connected!\n");

  if (read(client, buffer, sizeof(buffer)) < 0)
  {
    perror("Read socket failed!");
    close(client);
    close(server);
    return 1;
  }

  printf("Received data: %s\n", buffer);

  // In this example, we just convert the string to uppercase
  for (int i = 0; i < strlen(buffer); i++)
  {
    buffer[i] = toupper(buffer[i]);
  }

  if (write(client, buffer, strlen(buffer) + 1) < 0)
  {
    perror("Write socket failed!");
    close(client);
    close(server);
    return 1;
  }

  printf("Data sent to back to the client.\n");

  // Close sockets and exit
  close(client);
  close(server);
  return 0;
}