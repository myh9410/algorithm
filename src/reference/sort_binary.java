package reference;

import java.util.Scanner;
 /*



�����˻� : ������ �迭�� ����Ÿ���̽����� �ŵ� 2���Ͽ� ���ϴ� �ڷḦ ã�� ���. 

�����͸� ������ �� ������ ���� ũ�� �����ʿ� �����ϴ� ���(����Ű�� �ִ� ��
*/

public class sort_binary {

public static void main(String[] args) {
	int data[] = {2, 9, 15, 18, 34, 56, 62, 69, 81, 96};
	int key;
	// ��������Ÿ ���
	// for( int i=0; i<data.length; i++){
	// System.out.print(data[i] + " ");
	//}
	for(int value : data){
		System.out.print(value + " ");
	}
	System.out.println();
	// �˻�����Ÿ �Է�
	Scanner scanner = new Scanner(System.in);
	System.out.print("�˻� ����Ÿ �Է� : ");
	key = scanner.nextInt();
	// �����˻�
	int low = 0;
	int high = data.length - 1;
	int mid;
	boolean found = false;
	int pos = -1;
	while( !found && low <= high){
		mid = (low + high) / 2; // �߰���ġ ����
		if( key == data[mid]){
			found = true;
			pos = mid;
		}else if( key > data[mid]){ // ���� ���� ����
			low = mid + 1;
		}else{ // ���� ���� ����
			high = mid - 1;
		}
	}
	String result;
	if( found ){
		result = "�˻� ����! " + pos; 
	}else{
		result = "�˻� ����! (" + pos + ")";
	}
	System.out.println(result);
	}
}
