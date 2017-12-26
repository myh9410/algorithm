package reference;

import java.util.Scanner;
 /*



이진검색 : 순서로 배열된 데이타베이스에서 거듭 2분하여 원하는 자료를 찾는 방법. 

데이터를 저장할 때 작으면 왼쪽 크면 오른쪽에 저장하는 방식(가르키고 있는 것
*/

public class sort_binary {

public static void main(String[] args) {
	int data[] = {2, 9, 15, 18, 34, 56, 62, 69, 81, 96};
	int key;
	// 원본데이타 출력
	// for( int i=0; i<data.length; i++){
	// System.out.print(data[i] + " ");
	//}
	for(int value : data){
		System.out.print(value + " ");
	}
	System.out.println();
	// 검색데이타 입력
	Scanner scanner = new Scanner(System.in);
	System.out.print("검색 데이타 입력 : ");
	key = scanner.nextInt();
	// 이진검색
	int low = 0;
	int high = data.length - 1;
	int mid;
	boolean found = false;
	int pos = -1;
	while( !found && low <= high){
		mid = (low + high) / 2; // 중간위치 결정
		if( key == data[mid]){
			found = true;
			pos = mid;
		}else if( key > data[mid]){ // 하한 범위 조정
			low = mid + 1;
		}else{ // 상한 범위 조정
			high = mid - 1;
		}
	}
	String result;
	if( found ){
		result = "검색 성공! " + pos; 
	}else{
		result = "검색 실패! (" + pos + ")";
	}
	System.out.println(result);
	}
}
