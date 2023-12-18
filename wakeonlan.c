/* 参考: https://www.geekpage.jp/programming/linux-network/broadcast.php */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    int yes = 1;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9);
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));

    unsigned char data[] = {255,255,255,255,255,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255,
                            170,187,204,221,238,255
    };

    sendto(sock, data, sizeof(data), 0, (struct sockaddr *)&addr, sizeof(addr));

    close(sock);

    return 0;
}

