CC=g++
CFLAGS=-Wall -g
all_sources=main.cpp System.cpp User.cpp Post.cpp
all_objs=$(all_sources:.c=.o)

SocialMediaApplication: $(all_objs)
	$(CC) $(CFLAGS) -o SocialMediaApplication $(all_objs)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f SocialMediaApplication *.o

