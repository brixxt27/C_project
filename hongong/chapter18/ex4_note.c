#include <stdio.h>

int	main(void)
{
	FILE	*fp;
	FILE	*ofp;
	int		age;
	char	name[20];

	// c.txt 파일을 작성한다. 없다면 생성한다.
	ofp = fopen("c.txt", "w");
	// c.txt 파일에 데이터를 작성한다.
	fprintf(ofp, "%d\n%s\n", 17, "Hong GD");
	// rewind함수를 사용해도 될 것이지만, 새로 file 구조체를 사용하여 파일을 읽는다.
	fclose(ofp);
	// fclose(ofp)를 여기서 해줘야 내가 원하는 age와 name 값을 출력 받을 수 있다.
	fp = fopen("c.txt", "r");
	fscanf(fp, "%d", &age);
	// fflush(fp) 를 사용하면 뒤에 있는 모든 데이터가 날아간다.
	fgetc(fp);
	fgets(name, sizeof(name), fp);
	printf("%d, %s\n", age, name);
	fclose(fp);
	//fclose(ofp);
	// fclose(ofp)를 여기서 하면 값이 이상하게 나온다.
	return (0);
}
