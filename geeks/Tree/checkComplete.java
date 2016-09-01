import java.util.LinkedList;
import java.util.Queue;
class Node{
	int info;
	Node left,right;
	Node(int data){
		info = data;
		left = right = null;
	}

}

class checkComplete{

	static boolean checkRecusion(Node root,int count,int i){
		if(root==null){
			return true;
		}
		if(i<count){
			return (checkRecusion(root.left,count,(2*i+1))&&checkRecusion(root.right,count,(2*i+2)));
		}
		else{
			return false;
		}
	}
	static boolean TestTree(Node root){
		Queue<Node> q = new LinkedList<Node>();
		int inCount=0,outCount=0;
		boolean leafFound=false;
		q.add(root);
		outCount++;
		Node temp;
		while(!q.isEmpty()){
			while(outCount>0){
				temp = q.remove();
				// if(temp==null){
				// 	System.out.println("temp is null");
				// }
				// else{
				// 	System.out.println("value = "+ temp.info);
				// }
				if((temp.left==null && temp.right!=null)){
					return false;
				}
				if(leafFound){
				if(temp.left!=null && temp.left!=null){
					return false;
				}
			}
			if( temp.right==null && !leafFound)
				{leafFound = true;
					//System.out.println("Here for value = "+temp.info);
					}
			else{
				if(temp.left!=null){
				q.add(temp.left);
				inCount++;}
				if(temp.left!=null){
				q.add(temp.right);
				inCount++;}
			}

				outCount--;	
			}
			outCount = inCount;
			inCount=0;
		}
		return true;
	}


	public static void main(String s[]){

		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.right.right = new Node(5);
		root.right.left = new Node(6);
		//root.left.right = new Node(10);
		if(checkRecusion(root,6,0)){
		System.out.println("Recusion says: A complete binary tree");	
		}
		else{
			System.out.println("Recusion says: Not complete binary tree");	
		}


		if(TestTree(root)){
		System.out.println("Iteration says: A complete binary tree");	
		}
		else{
			System.out.println("Iteration says: Not complete binary tree");	
		}
		

	}

}