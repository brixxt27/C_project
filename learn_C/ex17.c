#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void	die(const char *message);
struct	Connection *Database_open(const char *filename, char mode);
void	Database_create(struct Connection *conn);
void	Database_load(struct Connection *conn);
void	Database_write(struct Connection *conn);
void	Database_get(struct Connection *conn, int id);
void	Database_set(struct Connection *conn, int id, const char *name, const char *email);
void	Address_print(struct Address *addr);
void	Database_delete(struct Connection *conn, int id);
void	Database_list(struct Connection *conn);
void	Database_close(struct Connection *conn);

int	main(int argc, char *argv[])
{
	// ./ex17 db.dat c 같이 적어도 argc == 3 이어야 가능하다.
	// 이보다 적으면 에러 메시지를 띄운다.
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	// argv[1] 을 파일명으로 지정하고, action 을 지정하므로써 이후에 할 switch 문에 전해준다.
	char	*filename = argv[1];
	char	action = argv[2][0];
	// struct Connection
	// {
	// 	FILE *file;
	// 	struct Database *db;
	// };
	struct	Connection *conn = Database_open(filename, action);
	// id 는 저장할 data 의 항목 숫자이며, 처음에는 아무 것도 가리키지 않는 0으로 초기화한다.
	int		id = 0;

	// 인수가 3 보다 크다면 argv[3] 을 id로 한다. atoi 함수를 이용해 아스키 코드로 받은 문자를 int 형으로 바꿔 이후에 사용할 id 변수에 저장한다.
	if (argc > 3)
		id = atoi(argv[3]);
	// 글자 수를 100으로 지정했기 때문에 id 가 #define MAX_ROWS 100 을 넘어서면 에러 메시지를 띄운다.
	if (id >= MAX_ROWS)
		die("There's not that many records.");

	// argv[2][0]으로 지정했던 문자를 action 변수에 넣어 switch 문으로 앞으로 할 행동에 대해 지정한다.
	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4)
				die("Need an id to get");

			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6)
				die("Need an id to get");

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
				die("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return (0);
}

// 할당을 실패했거나 NULL 을 매개변수로 받았을 때 이를 방어해 UB를 방지하는 함수이다.
void	die(const char *message)
{
	// errno 으로 지정된 에러라면 perror 함수를 통해 에러 메시지 출력
	if (errno) {
		perror(message);
	}
	// errno 으로 지정된 것이 아니라면 직접 printf() 함수로 에러 메시지 출력한다.
	else {
		printf("ERROR: %s\n", message);
	}
	
	// 이후 exit 함수에 인수를 1 줌으로써 운영체제에게 정상종료 되지 않았다는 점을 알립니다.
	exit (1);
}

// argv[1] 으로 파일 명을 받아 저장하고, argv[2][0] 으로 이번에 할 행동을 지정한다.
struct Connection *Database_open(const char *filename, char mode)
{
	// struct Connection 자료형 크기만큼 해당 자료형을 가리키는 포인터 변수를 선언하여  malloc 으로 힙 영역에 할당 시켜준다.
	struct Connection *conn = malloc(sizeof(struct Connection));
	// conn 이 NULL 이라면 die 함수에 Memory error 내용으로 에러 메시지를 출력하도록 한다.
	if (!conn)
		die("Memory error");
	// 구조체 내에 있는 포인터 변수 같은 경우에는 그 변수가 가리키는 메모리 영역을 동적할당으로 지정하여 사용한다.
	conn -> db = malloc(sizeof(struct Database));
	if (!conn -> db)
		die("Memory error");

	if (mode == 'c')
		conn -> file = fopen(filename, "w");
	else
	{
		conn -> file = fopen(filename, "r+");
		
		if (conn -> file) {
			Database_load(conn);
		}
	}

	if (!conn -> file)
		die("Failed to open the file");

	return (conn);
}

void	Database_create(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {
		// 초기화 용도로 사용할 프로토 타입을 만든다.
		struct Address addr = { .id = i, .set = 0 };
		// 이제 지정만 하면 된다.
		conn -> db -> rows[i] = addr;
	}
}

void	Database_load(struct Connection *conn)
{
	int rc = fread(conn -> db, sizeof(struct Database), 1, conn -> file);
	if (rc != 1)
		die("Failed to load database.");
}

void	Database_write(struct Connection *conn)
{
	rewind(conn -> file);

	// rc 는 하나의 flag 변수로 fwrite와 fflush 함수의 반환값을 판별하는 변수
	int rc = fwrite(conn -> db, sizeof(struct Database), 1, conn -> file);
	if (rc != 1)
		die("Failed to write database.");

	rc = fflush(conn -> file);
	if (rc == -1)
		die("Cannot flush database.");
}

void	Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn -> db -> rows[id];

	if (addr -> set) {
		Address_print(addr);
	}
	else {
		die("ID is not set");
	}
}

void	Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn -> db -> rows[id];
	if (addr -> set)
		die("Already set, delete it first");

	addr -> set = 1;
	// 경고: 버그임. "프로그램 깨뜨리기" 섹션을 읽고 고칠 것
	char *res = strncpy(addr -> name, name, MAX_DATA);
	//strncpy 버그를 보여줌
	if (!res)
		die("Name copy failed");

	res = strncpy(addr -> email, email, MAX_DATA);
	if (!res)
		die("Email copy failed");
}

void	Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr -> id, addr -> name, addr -> email);
}

void	Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn -> db -> rows[id] = addr;
}

void	Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn -> db;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db -> rows[i];

		if (cur -> set) {
			Address_print(cur);
		}
	}
}

void	Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn -> file)
			fclose(conn -> file);
		if (conn -> db)
			free(conn -> db);
		free(conn);
	}
}
