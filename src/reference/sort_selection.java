package reference;

import java.util.Scanner;
 //선택정렬 :  정렬되지 않은 데이터들에 대해 가장 작은 데이터를 찾아 가장 앞의 데이터와 교환해나가는 방식이다
public class sort_selection {
    public static void main(String args[]){
    	int data[] = { 72, 45, 23, 39, 81, 56, 12, 4, 95, 87 }; // 원본배열
    	int temp;
    	System.out.print("정렬전 데이타 : ");
    	printArray(data);
    	for(int i=0; i < data.length - 1; i++){ // 기준위치를 0~n-2 까지 
    		for(int j=i+1; j < data.length; j++){// 나머지값 위치는 기준위치+1 ~ n-1까지
    			if( data[i] > data[j]){ 
    				temp = data[i];
    				data[i] = data[j];
    				data[j] = temp;
    			}
    		}
    	} 
    	System.out.print("선택 정렬 후 데이타 : ");
    	printArray(data);
    }
static void printArray(int data[]){
	for(int i=0; i<data.length; i++){
		System.out.print( data[i] + " ");
	}
System.out.println();
}
}
