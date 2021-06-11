void ReadS(char gomla[])
{
	char c ;
	while(c!='$')
	{
c= Read();
	}
	do
	{
strncat(gomla,&c,1);
c= Read();
	}while(c!='\n');
printS(gomla);
printS("\r\n");
}
