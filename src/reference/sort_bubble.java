package reference;

import java.util.Random;
import java.util.Scanner;
 //버블정렬(Bubble sort) : 버블 정렬(bubble sort)은 서로 이웃한 데이터들을 비교하며 가장 큰 데이터를 가장 뒤로 보내며 정렬하는 방식이다.
public class sort_bubble {

public static void main(String[] args) {
//int data[] = { 9, 5, 2, 4, 8 };
	int data[] = new int[10];
	Random random = new Random();
	for(int k=0; k<data.length; k++){
		data[k] = random.nextInt(100) + 1;
	}
	int temp;
	//버블정렬로 오름차순으로 나열하시오
	//원본데이타
	for(int k=0; k<data.length; k++){
		System.out.print( data[k] + " ");
	}
	System.out.println();
	// 버블정렬
	for(int i=0; i < data.length-1; i++){
		for(int j=0;j < data.length-i-1;j++){
			// 인접한 두값비교(j번째, j+1번째)
			if( data[j] > data[j+1]){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			} 
		}
		// 중간결과를 출력해 보자
		System.out.print( i + "번째 결과 : ");
		for(int k=0; k<data.length; k++){
			System.out.print(data[k] + " ");
		}
		System.out.println();
	}
	}
}
