package reference;

import java.util.Random;
import java.util.Scanner;
 //��������(Bubble sort) : ���� ����(bubble sort)�� ���� �̿��� �����͵��� ���ϸ� ���� ū �����͸� ���� �ڷ� ������ �����ϴ� ����̴�.
public class sort_bubble {

public static void main(String[] args) {
//int data[] = { 9, 5, 2, 4, 8 };
	int data[] = new int[10];
	Random random = new Random();
	for(int k=0; k<data.length; k++){
		data[k] = random.nextInt(100) + 1;
	}
	int temp;
	//�������ķ� ������������ �����Ͻÿ�
	//��������Ÿ
	for(int k=0; k<data.length; k++){
		System.out.print( data[k] + " ");
	}
	System.out.println();
	// ��������
	for(int i=0; i < data.length-1; i++){
		for(int j=0;j < data.length-i-1;j++){
			// ������ �ΰ���(j��°, j+1��°)
			if( data[j] > data[j+1]){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			} 
		}
		// �߰������ ����� ����
		System.out.print( i + "��° ��� : ");
		for(int k=0; k<data.length; k++){
			System.out.print(data[k] + " ");
		}
		System.out.println();
	}
	}
}
