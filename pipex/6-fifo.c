
/* pipe(fd) allows fd communication between parent and child, since fd are 
 * inherited into the subprocess.
 * fifo allows fd communication between the same level of hierarchy, and forces
 * freeze into process until there's both read and write communication into FIFO
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int	main(int ac, char *av[], char *env[])
{
	int	fd;
	int	x;

	if (mkfifo("myfifo1", 0777) == -1)
		if (errno != EEXIST)//if the file already exists!
			return 1;
	printf("Opening...\n");
	fd = open("myfifo1", O_RDWR);// CHECK FIFO BLOCKING!
	if (fd == -1)
		return 2;
	printf("Opened and now writting...\n");
	x = '@';
	if (write(fd, &x, sizeof(x)) == -1)
		return 3;
	printf("Written\n");
	close (fd);
	printf("Closed\n");
	return (0);
}
