#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char username[100];
	char password[7];
	int money;
	
	struct Account *next;
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL;//ָ��β����ָ�� 
Account * curAccount=NULL;//ָ��ǰ��¼�˻���ָ�� 

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %s %d\n",curP->name,curP->username,curP->password,curP->money);
			curP=curP->next;
		}
	}
	fclose(fp);
}
Account *haveAccount=NULL;
int findhaveAccount(char haveusername[])
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->username,haveusername)==0)
		{
			haveAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}


void signUpC()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("����������:\n");
	scanf("%s",newNodeP->name);
	
	printf("���������֤:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("������绰:\n");
	scanf("%s",newNodeP->tel);
	for(int m=4;m>0;m--)
	{
		printf("�������˺�:\n");
		scanf("%s",newNodeP->username);
		if(findhaveAccount(newNodeP->username))
		{
			printf("�˻��Ѵ��ڣ�\n");
			printf("���������룺");
		}
		else
		{
			printf("����������:\n");
			scanf("%s",newNodeP->password);
			
			newNodeP->money=0;
			newNodeP->next=NULL;
			
			if(head==NULL)
			{
				head=newNodeP;
				tail=newNodeP;
			}
			else
			{
				tail->next=newNodeP;
				tail=newNodeP;
			}
			saveData();
			printf("�����ɹ�!\n");
			
			break;
		}
	}
}
void signUpE()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("Please enter your name:\n");
	scanf("%s",newNodeP->name);
	
	printf("Please enter your idCard:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("Please enter your tel:\n");
	scanf("%s",newNodeP->tel);
    for( int m=4;m>0;m--)
	{
		printf("Please enter your username:\n");
		scanf("%s",newNodeP->username);
		if(findhaveAccount(newNodeP->username))
		{
			printf("Account already exists\n");
			printf("please re-enter��");
		}
		else
		{
			printf("Please enter your password:\n");
			scanf("%s",newNodeP->password);
			
			newNodeP->money=0;
			newNodeP->next=NULL;
			
			if(head==NULL)
			{
				head=newNodeP;
				tail=newNodeP;
			}
			else
			{
				tail->next=newNodeP;
				tail=newNodeP;
			}
			saveData();
			printf("Created successfully!\n");
			break;
		}
	}
	
}


//�ҵ�����1�����򷵻�0 
int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}

void updatePasswordC()
{
	char formerPassword[100]={'\0'};
	printf("����������룺");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("�����������룺");
		scanf("%s",curAccount->password);
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("������󣡲����޸ģ�\n");
	}
}

void updatePasswordE()
{
	char formerPassword[100]={'\0'};
	printf("please enter your former password��");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("please enter your new password��");
		scanf("%s",curAccount->password);
		printf("Modified successfully��\n");
	}
	else
	{
		printf("The password is wrong and cannot be modefied��\n");
	}
}


void saveMoneyC()
{
	printf("���������");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("���ɹ���\n");
	}
	else
	{
		printf("��������޷����\n");
	}
	
}
void saveMoneyE()
{
	printf("please enter the deposit amount��");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("deposit successful��\n");
	}
	else
	{
		printf("the amount does not match,so the deposit cannot be made");
	}
	
}
void drawMoneyC()
{
	printf("������ȡ���");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("ȡ��ɹ���\n");
		curAccount->money-=money;
		
	}
	else
	{
		printf("����!ȡ��ʧ��\n");
	}
	
}
void drawMoneyE()
{
	printf("please enter the withdrawal amount��");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("withdrawal successful��\n");
		curAccount->money-=money;
		
	}
	else
	{
		printf("wiyhdrawal failed due to insufficient balance\n");
	}
	
}

Account *otherAccount=NULL;
int findotherAccount(char otherusername[])
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->username,otherusername)==0)
		{
			otherAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}
void transferC()
{
	printf("������ת���˻���");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		
		printf("������ת�˽�");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{
			
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("ת�˳ɹ�\n");
		}
		else if(money>curAccount->money)
		{
			printf("���㣬�޷�ת�ˣ�\n");
		}
		else if(money%100!=0)
		{
			printf("ת�˽����Ϲ���\n");
		}
	}
	
	else
	{
		printf("�˻�����\n");
	}
}

void transferE()
{
	printf("please enter the transfer account��");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		
		printf("please enter the transfer amount��");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{
			
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("transfer succeeded!");
		}
		else
		{
			printf("Insufficient balance��unable to transfer��");
		}
	}
	
	else
	{
		printf("Account error��\n");
	}
}
void printLinkedListC()
{
	
	printf("������%s\t�˻���%s\t ��%d\n",curAccount->name,curAccount->username,curAccount->money);
	
	
}

void printLinkedListE()
{
	printf("name:%s\tUsername��%s\t balance��%d\n",curAccount->name,curAccount->username,curAccount->money);
	
}

void homePageC()
{
	while(1)
	{
		system("cls");
		printf("1���޸�����   2�����    3��ȡ��    4��ת��    5����ѯ   0������\n");
		
		int gn;
		scanf("%d",&gn);
		if(gn==1)
		{
			updatePasswordC();
			system("pause");
		}
		else if(gn==2)
		{
			saveMoneyC();
			system("pause");
		}
		else if(gn==3)
		{
			drawMoneyC();
			system("pause");
		}
		else if(gn==4)
		{
			transferC();
			system("pause");
		}
		else if(gn==5)
		{
			printLinkedListC();
			system("pause");
		}
		else if(gn==0)
		{
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
}

void homePageE()
{
	while(1)
	{
		system("cls");
		printf("1: change the password   2:deposit   3:withdraw    4:transfer  5:query  6:return");
		int gn;
		scanf("%d",&gn);
		if(gn==1)
		{
			updatePasswordE();
			system("pause");
		}
		else if(gn==2)
		{
			saveMoneyE();
			system("pause");
		}
		else if(gn==3)
		{
			drawMoneyE();
			system("pause");
		}
		else if(gn==4)
		{
			transferE();
			system("pause");
		}
		else if(gn==5)
		{
			void printLinkedListE();
			system("pause");
			
		}
		else if(gn==0)
		{
			break;
		}
		else
		{
			printf("Input error\n");
		}
	}
}
void signInC()
{
	for(int i=0;i<3;i++)
	{
		Account a; 
		printf("��ӭ��¼\n");
		printf("�������˺ţ�\n");
		scanf("%s",a.username);
		
		printf("���������룺\n");
		scanf("%s",a.password);
		if(findAccount(a))
		{
			homePageC();
			
			return;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}
	} 
}
void signInE()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("Please enter your username:");
		scanf("%s",a.username);
		
		printf("Please enter your password:");
		scanf("%s",a.password);
		
		if(findAccount(a)==1)
		{
			homePageE();
			return;
		}
		else
		{
			printf("Login failed��\n");
		}
	}
}

/**
������ݼ��سɹ�����1
���򷵻�0 
*/
int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0; 
	}
	else
	{
		while(!feof(fp))
		{
			//������㣺�ڶ�������һ���ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
			Account * newNodeP=(Account *)malloc(sizeof(Account)); 
			
			//��㸳ֵ������ʼ��
			newNodeP->next=NULL;
			fscanf(fp,"%s %s %s %d\n",newNodeP->name,newNodeP->username,newNodeP->password,&newNodeP->money);
			
			//��ӽ�㵽����
			if(head==NULL)
			{
				head=newNodeP;
				tail=newNodeP;
			}
			else
			{
				tail->next=newNodeP;
				tail=newNodeP;
			}
		}
		return 1;
	}
	fclose(fp);
}

void showMenuC()
{
	while(1)
	{
		system("cls");
		printf("1:����   2:��¼   0������\n");
		
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpC();
			system("pause");
		}
		else if(n==2)
		{
			
			signInC();
			saveData();
			system("pause");
		}
		else if(n==0)
		{
			break;
		}
		
		
		else
		{
			printf("�������\n");
			Sleep(1200);
		}
	}
}

void showMenuE()
{
	while(1)
	{
		printf("1:signUp  2:signIn  3:return\n");
		int n;
		scanf("%d",&n);
		
		if(n==1)
		{
			signUpE();
			system("pause");
		}
		else if(n==2)
		{
			
			signInE();
			saveData();
			system("pause");
			
		}
		else if(n==0)
		{
			break;
		}
		else
		{
			printf("Input error��\n");
			Sleep(1200);
			
		}
	}
}
int main()
{
	
	while(1)
	{	
		system("cls");	
		printf("��ӭʹ���������\n");
		printf("Welcome to Tiandi bank\n");
		
		int language;
		printf("��ѡ������\n");
		printf("please select a language\n");
		printf("���ģ���1\n");
		printf("English, input 2\n");
		scanf("%d",&language);
		if(language==1)
		{
			int status=loadData();
			if(status==1)
			{
				printf("���سɹ���\n");
				showMenuC();
				
				
			}
			else
			{
				printf("����ʧ�ܣ�\n");
			}
			
		}
		else if(language==2)
		{
			int status=loadData();
			if(status==1)
			{
				printf("Load successful��\n");
				showMenuE();
				
			}
			else
			{
				printf("failed to load��\n");
			}
			
		}
		else if(language==0)
		{
			break;
		}
		else
		{
			printf("�������\n");
			printf("Input error");
			Sleep(1200);
		}
	}
				saveData();
				return 0;
} 
