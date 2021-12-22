/*
   1. stdio.h 는 printf와 각종 파일 입출력 함수를 사용하기 위해 포함
   2. assert.h 는 인수로 준 조건의 진위를 확인하는 assert 함수를 사용하기 위해 포함
   3. stdlib.h 는 exit 함수를 이용해 error가 나타날 시 프로그램을 종료하기 위해 포함
   4. errno.h 는 errno을 이용해 해당 에러가 어떤 에러인지 나타내기 위해 포함
   5. string.h 는 strncpy 함수를 이용해 복사 string을 복사하기 위해 포함
   */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
	1. MAX_DATA 와 MAX_ROWS 를 각각 512 와 100으로 전처리 과정에서 변경해줌.
   */
#define MAX_DATA 512
#define MAX_ROWS 100

/*
	1. 사용자의 정보를 담기 위한 구조체
	2. 필요한 데이터가 모두 다른 자료형을 가지고 있어도 쉽게 구조체로 관리 가능 
   */
struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

	/*
   1. 여러 사람의 데이터를 배열로 관리 가능
	*/

struct Database {
	struct Address rows[MAX_ROWS];
};

/*
	1. 파일 입출력하기 위해 FILE 구조체 포인터 변수 선언
	2. Database 포인터 변수 선언. heap 영역에 동적할당 시키기 위해서이다.
	*/
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

/*
   1. argc 가 3 미만일 때 실행하지 않고, 에러 메시지를 출력하며 프로그램 종료한다. 에러 메시지로는 어떤 형식으로 명령행 인자를 줘야 하는지 알려준다.
   2. argv[1]은 파일의 이름으로 지정하고, argv[2][0]는 action 으로 지정한다.
   3. Database_open 함수에 filename 과 action 을 인수로 넘긴다.
   id = 0 으로 초기화해둔다.
   4.. argv[3]은 id를 적는 곳이다. argc > 3일 때 argv[3]으로 들어온 것은 문자열로 들어오니 atoi 함수를 이용해 int형으로 변환해준다.
   5. 명령행 인자로 filename, action 을 받고, action에 해당하는 switch!문으로 가서 실행
   */
int	main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char	*filename = argv[1];
	char	action = argv[2][0];
	struct	Connection *conn = Database_open(filename, action);
	int		id = 0;

	if (argc > 3)
		id = atoi(argv[3]);
	if (id >= MAX_ROWS)
		die("There's not that many records.");

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

// Error 발생 시 에러 사항 출력 후 프로그램 종료
void	die(const char *message)
{
	if (errno) {
		perror(message);
	}
	else {
		printf("ERROR: %s\n", message);
	}
	
	exit (1);
}

/*
1. conn 구조체 포인터 변수가 struct Connection 자료형 변수를 가리키게 한다. 스텍에 선언하지 않고 heap에 선언한 이유는 많은 데이터를 다룰 때는 heap을 이용하기 때문이다.
2. conn -> db 도 동적할당 시켜준다. 위와 같은 이유로 heap 영역에 선언.
3. c mode 일 경우에 파일을 생성하기 위해 w 옵션으로 fopen 함수를 연다. c일 경우는 파일이 존재하지 않을 경우이다.
4. c mode 가 아닐 경우에 r+ 옵션으로 fopen 함수를 실행한다. c가 아닐 경우라는 것은 이미 파일이 존재한다는 의미이다. 
5. c가 아니었는데 파일이 존재하면 Database_load 함수에 conn을 넘긴다. 반대라면 아래 if 문에서 die 함수를 통해 에러 메시지를 출력하고 종료.
6. 성공적으로 fopen 함수를 실행하면 conn을 반환한다.
   */
struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error");
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
/* 
   1. Database_open 함수에서 c mode가 아닐 때 fopen 함수로 성공적으로 r+ 옵션을 실행했다면 이 함수로 들어오게 된다.
   2. size_t fread(void *ptr, size_t size(각 원소의 크기), size_t count(읽어들일 원소의 개수), FILE *stream);
   3. int 형 변수 rc에 fread 함수의 반환값을 넣는다. 이 때 성공적으로 fread 함수를 실행했다면 읽어들인 원소의 개수를 반환하므로 1을 반환한다.
   */
void	Database_load(struct Connection *conn)
{
	int rc = fread(conn -> db, sizeof(struct Database), 1, conn -> file);
	if (rc != 1)
		die("Failed to load database.");
}

void	Database_create(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {
		struct Address addr = { .id = i, .set = 0 };
		conn -> db -> rows[i] = addr;
	}
}

void	Database_write(struct Connection *conn)
{
	rewind(conn -> file);

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
	char *res = strncpy(addr -> name, name, MAX_DATA);
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
