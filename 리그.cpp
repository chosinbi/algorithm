#include <iostream>
using namespace std;

void scorecal(int a[],int** totalscore);
void output(int** totalscore,int n);
void quicksort(int** a, int first, int last);
void swapElements(int** a, int first, int last);
int partition(int** a, int first, int last);

int main()
{
	//2<=N<=100
	int n;
	while (1) {
		cin >> n;
		if (n >= 2 && n <= 100) break;
	}  //���� �� �Է¹ޱ�

	int** totalscore = new int*[n];//�� ���� ������ ������ �迭 ����
	for (int i = 0; i < n; i++)
		totalscore[i] = new int[2];
	for (int i = 0; i < n; i++) {
		totalscore[i][0] = i + 1;
		totalscore[i][1] = 0; //������ ���ذ��� �ǹǷ� 0���� �ʱ�ȭ�����ش�.
	}
	int play((n*(n - 1))/ 2); //�� ��� �� 
	
	int *note = new int[4];  //�� ���� ���� ��Ȳ �Է� �ޱ� ���� �迭 ����
	for (int i = 0; i < play; i++) {
		cin >> note[0] >> note[1] >> note[2] >> note[3];
		scorecal(note,totalscore);
	}
	quicksort(totalscore, 0, n - 1);
	output(totalscore, n);

	/*cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << totalscore[i][0]
			<< " " << totalscore[i][1] << endl; 
	}
	*/

	return 0;

}
void scorecal(int a[],int **totalscore) {
	
	if (a[2] > a[3]) totalscore[a[0]-1][1] += 3;
	else if (a[2] < a[3]) totalscore[a[1] - 1][1] += 3;
	else {
		
		totalscore[a[0]-1][1] += 1;
		totalscore[a[1]-1][1] += 1;
	}

}
void output(int** a,int n) {
	int temp(a[0][1]);//���� ������� Ȯ���ϱ� ���� �ӽ� ���� ����
	int ord(1); //1�� ���� ����

	int* res = new int[n];//������� ����
	/*for (int i = 0; i < n; i++)
		rank[i] = new int[2];
*/
	for (int i = 0; i < n; i++) {
		if (i != 0 && (a[i][1] == temp)) {
			ord--;
			res[a[i][0] - 1] = ord;
			ord ++;
		}
		else  res[a[i][0] - 1] = ord;
		temp=a[i][1];
		ord++;
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << res[i] << endl; //
}

void quicksort(int** a, int first, int last)
{
	if (first >= last)
		return;
	int split(partition(a, first, last));

	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
}
int partition(int** a, int first, int last)
{
	int lastSmall(first), i;

	for (i = first + 1; i <= last; i++)
		// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]

		if (a[i][1] >= a[first][1]) { // key comparison
			++lastSmall;
			swapElements(a, lastSmall, i);
		}

	swapElements(a, first, lastSmall); // put pivot into correct position
									   // postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
									   //    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}
void swapElements(int** a, int first, int last) {
	int temp1(a[last][0]),temp2(a[last][1]);

	a[last][0] = a[first][0];
	a[last][1] = a[first][1];

	a[first][0] = temp1;
	a[first][1] = temp2;
}

