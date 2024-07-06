#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/buffer_driver"
#define WRITE_DATA "Long string to read!"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    ssize_t bytes_written, bytes_read;
    char read_buffer[BUFFER_SIZE];

    // Apri il file del dispositivo
    fd = open(DEVICE_PATH, O_RDWR);  // Apri in modalità lettura/scrittura
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    // Scrivi dati nel dispositivo
    bytes_written = write(fd, WRITE_DATA, strlen(WRITE_DATA) + 1);  // +1 per il terminatore di stringa
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }
    printf("Wrote %zd bytes to the device: %s\n", bytes_written, WRITE_DATA);

    // Leggi dati dal dispositivo
    memset(read_buffer, 0, BUFFER_SIZE);  // Pulisci il buffer di lettura
    bytes_read = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }
    printf("Read %zd bytes from the device: %s\n", bytes_read, read_buffer);

    // Chiudi il file del dispositivo
    close(fd);

    return 0;
}
