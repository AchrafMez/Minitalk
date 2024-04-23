#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// void signal_handler(int signum)
// {
//   printf("Received SIGINT!\n", signum);
//   exit(0);
// }

// int main()
// {
//   // Set the signal handler for the SIGINT and SIGTERM signals
//   // to the signal_handler function

//   signal(SIGINT, signal_handler);
//   signal(SIGTERM, signal_handler);

//   while (1) {
//     // Do some work here...
//   }

//   return (0);
// }

// #include <stdio.h>
// #include <unistd.h>

// int main(void) {
//     printf("Sleeping for 500000 microseconds...\n");
//     usleep(500000);
//     printf("Done sleeping.\n");
//     return (0);
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     printf("Exiting with status 0...\n");
//     exit(0);
// }

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void sighandler(int);

// int main () {
//    signal(SIGINT, sighandler);

//    while(1) {
//     printf("Going to sleep for a second...\n");
//     printf("%d", getpid());
//     sleep(1);
//    }
//    return(0);
// }

// void sighandler(int signum) {
//    printf("Caught signal %d, coming out...\n", signum);
//    exit(1);
// }

//
// void send_signal(unsigned char character)
// {
//  int    i;
//  unsigned char temp_char;

//  i = 8;
//  temp_char = character;
//  while (i > 0)
//  {
//   i--;
//   temp_char = character >> i;
//   write(1, &temp_char, 1);
// //   if (temp_char % 2 == 0)
// //    kill(pid, SIGUSR2);
// //   else
// //    kill(pid, SIGUSR1);
// //   usleep(42);
//  }
// }
// int main(int ac, char **av)
// {
//    (void)ac;
//    // int pid = atoi(av[1]);
//    char *text = av[2];
//    int i = 0;
//    while(text[i])
//       send_signal(text[i++]);
//    send_signal('\0');

// }

void	convert(const char *str)
{
	int				i;
	unsigned char	bit;
	int				j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 8;
		while (i--)
		{
			bit = (str[j] >> i & 1) + '0';
			write(1, &bit, 1);
		}
		write(1, " ", 1);
		j++;
	}
}
int	main(void)
{
	while (1)
	{
	}

	convert("abc");
}