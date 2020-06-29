#include <iostream>//C++�����������׼��
#include <fstream>//C++�ļ�����׼��
#include <iomanip>//C++����������ݱ�׼��
#include <string>//C++String���׼��
using namespace std;

///C++��׼��C++11
///Windows SDK �汾��10.0.17763.0
///ƽ̨���߼���Visual Studio 2019 (v142)

#pragma region ȫ�ֱ�������
///
///ȫ�ֱ�������
///

int stu_num = 0;//ѧ��ʵ������
int course_num = 0;//�γ�ʵ������
int course_scores_sum[6] = { 0 };//�γ��ܷ�
float course_scores_average[6] = { 0 };//�γ�ƽ����
int t = 0;//ȫ������ִ�в���������t=1ʱ�˳�whileѭ��

//����ṹ�����͡�ѧ���ɼ���
struct student_scores {
	int stu_id = 0;//ѧ��ѧ��
	string stu_name = "";//ѧ������
	int stu_score[6] = { 0 };//���ſγ̵ĳɼ����γ���󲻳���6�ţ�
	int stu_sum = 0;//ѧ�����ܷ�
	float stu_average = 0;//ѧ����ƽ����
	int stu_rank = 0;//ѧ���ɼ���������
};

#pragma endregion


#pragma region ȫ�ֺ�������
///
///ȫ�ֺ�������
///

//ѧ���ɼ�¼�������¼�
void load_student_scores_sum_and_average(student_scores stu[], int n);
void load_score_list(student_scores stu[], int n);
void score_loading(student_scores stu[])//ѧ���ɼ�һ��¼����ϣ�����ִ���ܷ֡�ƽ���֡������ļ���
{
	load_student_scores_sum_and_average(stu, stu_num);
	load_score_list(stu, stu_num);
}

//ѧ���ɼ���������ӡ
void score_title()
{
	cout << "ID" << "\t\t" << "Name" << "\t";
	for (int i = 0; i < course_num; i++)
		cout << "Course" << i + 1 << "\t";
	cout << "Sum" << "\t" << "Average" << "\t" << "Rank" << endl;
}

//ѧ���ɼ�������Գɼ����ķ�ʽ�����
void score_bar(student_scores stu[], int a)//aΪѧ�����
{
	cout << stu[a].stu_id << "\t" << stu[a].stu_name << "\t";
	for (int i = 0; i < course_num; i++)
		cout << stu[a].stu_score[i] << "\t";
	cout << stu[a].stu_sum << "\t" << setiosflags(ios::fixed) << setprecision(2) << stu[a].stu_average << "\t";
	cout << stu[a].stu_rank << endl;
}

#pragma endregion


#pragma region ��������
///
///��������
///

//�˵�1 - ¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
void student_scores_input(student_scores stu[], int n)//nΪѧ��ʵ������
{
	cout << "Input course number(m<=6):" << endl;
	t = 0;
	while (t == 0)
	{
		if (cin >> course_num)
			t = 1;
		else
		{
			cout << "Input error!" << endl;
			cin.clear(); //��cin���±��Ϊ��ȷ���Դﵽ���������Ŀ��
			while (cin.get() != '\n')	 //���֮ǰcin������������
				continue;
		}
	}

	cout << "Input student's ID, name and score:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].stu_id >> stu[i].stu_name;
		for (int j = 0; j < course_num; j++)
		{
			cin >> stu[i].stu_score[j];
		}
	}
}

//�˵�2 - ����ÿ�ſγ̵��ֺܷ�ƽ����
void course_scores_sum_and_average(student_scores stu[], int n)//nΪѧ��ʵ������
{
	//���㲿��
	for (int i = 0; i < course_num; i++)//�������ÿ�ſγ̵�ƽ���ֺ��ܷ�
	{
		for (int k = 0; k < n; k++)//�ۼ�ÿ��ѧ����Ӧ�γ̵ķ���
		{
			course_scores_sum[i] = course_scores_sum[i] + stu[k].stu_score[i];
		}
		course_scores_average[i] = float(course_scores_sum[i]) / n;
	}
	//�������
	for (int i = 0; i < course_num; i++)
	{
		cout << "course" << i + 1 << ": sum=" << course_scores_sum[i] << setiosflags(ios::fixed) << setprecision(2) << ", aver=" << course_scores_average[i] << endl;
	}
}

//�˵�3 - ����ÿ��ѧ�����ֺܷ�ƽ���֣��ɼ�¼���������ɼ��㲿�֣�
void load_student_scores_sum_and_average(student_scores stu[], int n)//nΪѧ��ʵ������
{
	//���㲿��
	for (int i = 0; i < n; i++)//�������ÿ��ѧ�����ֺܷ�ƽ����
	{
		for (int j = 0; j < course_num; j++)//�ۼӶ�Ӧѧ��ÿ�ſγ̵ķ���
		{
			stu[i].stu_sum = stu[i].stu_sum + stu[i].stu_score[j];
		}
		stu[i].stu_average = float(stu[i].stu_sum) / course_num;
	}
}

//�˵�3 - ����ÿ��ѧ�����ֺܷ�ƽ����
void student_scores_sum_and_average(student_scores stu[], int n)//nΪѧ��ʵ������
{
	//�������
	for (int i = 0; i < n; i++)
	{
		cout << stu[i].stu_name << ": sum=" << stu[i].stu_sum << setiosflags(ios::fixed) << setprecision(2) << ", aver=" << stu[i].stu_average << endl;
	}
}

//�˵�11 - ���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����
void score_output(student_scores stu[], int n)//nΪѧ��ʵ������
{
	score_title();
	for (int i = 0; i < n; i++)//������ѧ���ĳɼ���
	{
		score_bar(stu, i);
	}
}

#pragma endregion


#pragma region ������
///
///������
///

//����ѧ���ܷ����������ɼ�¼�����������������㣩
void load_score_list(student_scores stu[], int n)
{
	int a;
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
		temp[i] = stu[i].stu_sum;
	for (int i = 0; i < n; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
			a = temp[j] > temp[a] ? j : a;
		temp[a] = 0;
		stu[a].stu_rank = i + 1;
	}
}

//�˵� 4/5 - ��ÿ��ѧ�����ܷ� �ɸߵ���/�ɵ͵��� �ų����α�
void score_list(student_scores stu[], int n, int high_low)
{
	cout << "Sort in ascending order by score :" << endl;
	score_title();
	if (high_low == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (stu[j].stu_rank == i)
					score_bar(stu, j);
			}
		}
	}
	else
	{
		for (int i = n; i >= 1; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (stu[j].stu_rank == i)
					score_bar(stu, j);
			}
		}
	}
}

//�˵�6 - ��ѧ����С�����ų��ɼ���
void id_list(student_scores stu[], int n)
{
	cout << "Sort in ascending order by number :" << endl;
	int a;
	int* temp = new int[n];
	for (int i = 0; i < n; i++)
		temp[i] = stu[i].stu_id;
	score_title();
	for (int i = 0; i < n; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
			a = temp[j] < temp[a] ? j : a;
		temp[a] = 99999999;
		score_bar(stu, a);
	}
	cout << endl;
}


//�˵�7 - ���������ֵ�˳���ų��ɼ���
void name_list(student_scores stu[], int n)
{
	cout << "Sort in dictionary order by name:" << endl;
	int a;
	string *temp = new string[n];
	for (int i = 0; i < n; i++)
		temp[i] = stu[i].stu_name;
	score_title();
	for (int i = 0; i < n; i++)
	{
		a = 0;
		for (int j = 0; j < n; j++)
			a = temp[j] < temp[a] ? j : a;
		temp[a] = "~";
		score_bar(stu, a);
	}
	cout << endl;
}
#pragma endregion


#pragma region ��ѯ����
///
///��ѯ����
///

//�˵�8 - ��ѧ�Ų�ѯѧ���������俼�Գɼ�
void checking_out_for_id(student_scores stu[], int n)//nΪѧ��ʵ������
{
	cout << "Input the number you want to search:" << endl;
	int checking_stu_id = 0;//����ѯ��ѧ��ѧ��
	cin >> checking_stu_id;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].stu_id == checking_stu_id)
		{
			score_title();
			score_bar(stu, i);
			break;
		}
	}
	if (stu[i].stu_id != checking_stu_id)
		cout << "Not found!" << endl;
}

//�˵�9 - ��������ѯѧ���������俼�Գɼ�
void checking_out_for_name(student_scores stu[], int n)//nΪѧ��ʵ������
{
	cout << "Input the name you want to search:" << endl;
	string checking_stu_name;//����ѯѧ��������
	cin >> checking_stu_name;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].stu_name == checking_stu_name)
		{
			score_title();
			score_bar(stu, i);
			break;
		}
	}
	if (stu[i].stu_name != checking_stu_name)
		cout << "Not found!" << endl;
}

#pragma endregion


#pragma region ͳ�ƹ���
///
///ͳ�ƹ���
///

//�˵�10 - ��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
void count(student_scores stu[])
{
	int peo[6] = {0};
	int n = 1;
	for (int i = 0; i < stu_num; i++)
		peo[i] = 0;
	while (n <= course_num)
	{
		printf("For course %d\n", n);
		for (int i = 0; i < stu_num; i++)
		{
			if (stu[i].stu_score[n - 1] < 60) peo[0]++;
			else if (stu[i].stu_score[n - 1] < 70 && stu[i].stu_score[n - 1] >= 60) peo[1]++;
			else if (stu[i].stu_score[n - 1] < 80 && stu[i].stu_score[n - 1] >= 70) peo[2]++;
			else if (stu[i].stu_score[n - 1] < 90 && stu[i].stu_score[n - 1] >= 80) peo[3]++;
			else if (stu[i].stu_score[n - 1] < 100 && stu[i].stu_score[n - 1] >= 90) peo[4]++;
			else peo[5]++;
		}
		printf("<60\t%d\t%.2f%%\n", peo[0], 100 * (double)peo[0] / (double)stu_num);
		printf("60-69\t%d\t%.2f%%\n", peo[1], 100 * (double)peo[1] / (double)stu_num);
		printf("70-79\t%d\t%.2f%%\n", peo[2], 100 * (double)peo[2] / (double)stu_num);
		printf("80-89\t%d\t%.2f%%\n", peo[3], 100 * (double)peo[3] / (double)stu_num);
		printf("90-99\t%d\t%.2f%%\n", peo[4], 100 * (double)peo[4] / (double)stu_num);
		printf("100\t%d\t%.2f%%\n", peo[5], 100 * (double)peo[5] / (double)stu_num);
		for (int i = 0; i < stu_num; i++)
			peo[i] = 0;
		n++;
	}
}


#pragma endregion


#pragma region �ָ��뱸�ݹ���
///
///�ָ��뱸�ݹ���
///

//�˵�12 - �ָ�ѧ���ɼ�����
void recovery(student_scores stu[], int n)
{
	cout << "Input course number(m<=6):" << endl;
	cin >> course_num;
	ifstream fin("scores record.txt");
	for (int i = 0; i < n; i++)
	{
		fin >> stu[i].stu_id >> stu[i].stu_name;
		for (int j = 0; j < course_num; j++)
			fin >> stu[i].stu_score[j];
	}
	fin.close();
	cout << "Recovery successfully." << endl;
}

//�˵�13 - ����ѧ���ɼ�����
void backup(student_scores stu[], int n)
{
	ofstream fout("scores record.txt");
	for (int i = 0; i < n; i++)
	{
		fout << stu[i].stu_id << "\t" << stu[i].stu_name << "\t";
		for (int j = 0; j < course_num; j++)
			fout << stu[i].stu_score[j] << "\t";
		fout << endl;
	}
	fout.close();
	cout << "Backup successfully." << endl;
}

#pragma endregion


#pragma region ������
///
///������
///

int main()
{
	//����ѧ������
	cout << "Input student number(n<30):" << endl;
	t = 0;
	while (t == 0)
	{
		if (cin >> stu_num)
			t = 1;
		else
		{
			cout << "Input error!" << endl;
			cin.clear(); //��cin���±��Ϊ��ȷ���Դﵽ���������Ŀ��
			while (cin.get() != '\n')	 //���֮ǰcin������������
				continue;
		}
	}
	student_scores stu[30];//ѧ������������30��

	#if 0
	//if 0 ʱ�ô���Ƭ�δ���ע��״̬��if 1 ʱ�ô���Ƭ�λ�ִ��
	//���ڳ����ʼ��ʱ�Զ�ע���������ݣ�����ִ�С��˵�ѡ��1�����Ӷ�����ֱ�ӵ��������˵�ѡ���ģ��
	//��������ģ��ʱ����Ѷ�Ӧģ�麯�����õ�stu���ⲿ!����Ϊstu2
	stu_num = 6;
	course_num = 3;
	student_scores stu2[6] =
	{
		{11003001,"lisi",87,82,89},
		{11003005,"heli",98,92,90},
		{11003003,"ludi",75,78,80},
		{11003002,"dumo",48,50,67},
		{11003004,"zuma",65,69,72},
		{11003006,"suyu",100,95,94}
	};
	#endif

	//�����������ʾ
	while (1)
	{
		int menu = 0; //�˵�ѡ��
		cout << "Management for Students' scores" << endl //ѧ���ɼ����� - ���˵�
			<< "1.Input record" << endl //��1��¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
			<< "2.Caculate total and average score of every course" << endl //��2������ÿ�ſγ̵��ֺܷ�ƽ����
			<< "3.Caculate total and average score of every student" << endl //��3������ÿ��ѧ�����ֺܷ�ƽ����
			<< "4.Sort in descending order by score" << endl //��4����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
			<< "5.Sort in ascending order by score" << endl //��5����ÿ��ѧ�����ܷ��ɵ͵����ų����α�
			<< "6.Sort in ascending order by number" << endl //��6����ѧ����С�����ų��ɼ���
			<< "7.Sort in dictionary order by name" << endl //��7�����������ֵ�˳���ų��ɼ���
			<< "8.Search by number" << endl //��8����ѧ�Ų�ѯѧ���������俼�Գɼ�
			<< "9.Search by name" << endl //��9����������ѯѧ���������俼�Գɼ�
			<< "10.Statistic analysis" << endl //��10����ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
			<< "11.List record" << endl //��11�����ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����
			<< "12.Recovery record" << endl //��12���ָ�ѧ���ɼ�����
			<< "13.Backup record" << endl //��13������ѧ���ɼ�����
			<< "0.Exit" << endl //�˳�����
			<< "Please Input your choice:" << endl;
		
		t = 0;
		while (t == 0)
		{
			if (cin >> menu)
				t = 1;
			else
			{
				cout << "Input error!" << endl;
				cin.clear(); //��cin���±��Ϊ��ȷ���Դﵽ���������Ŀ��
				while (cin.get() != '\n')	 //���֮ǰcin������������
					continue;
			}
		}

		switch (menu)
		{
		case 1:
			student_scores_input(stu, stu_num);
			score_loading(stu);
			break;
		case 2:
			course_scores_sum_and_average(stu, stu_num);
			break;
		case 3:
			student_scores_sum_and_average(stu, stu_num);
			break;
		case 4:
			score_list(stu, stu_num, 1);
			break;
		case 5:
			score_list(stu, stu_num, 0);
			break;
		case 6:
			id_list(stu, stu_num);
			break;
		case 7:
			name_list(stu, stu_num);
			break;
		case 8:
			checking_out_for_id(stu, stu_num);
			break;
		case 9:
			checking_out_for_name(stu, stu_num);
			break;
		case 10:
			count(stu);
			break;
		case 11:
			score_output(stu, stu_num);
			break;
		case 12:
			recovery(stu, stu_num);
			score_loading(stu);
			break;
		case 13:
			backup(stu, stu_num);
			break;
		case 0:
			cout << "End of program!" << endl;
			return 0;
		default:
			cout << "Input error!" << endl;
		}
	}
	
	return 0;
}

#pragma endregion