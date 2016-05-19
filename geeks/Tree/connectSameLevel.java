import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Node{
	Node left,right,nextRight;
	char data;

	Node(char data){
		this.data = data;
		left =right=nextRight= null;
	}
}

class connect{

	public void bfsVariant(Node root){
		int count;
		Node temp1,temp2;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);


		while(!q.isEmpty()){
			count = q.size();
			while(count>0){
				temp1 = q.poll();
				if(count>1)
					temp2 = q.peek();
				else
					temp2 = null;
				temp1.nextRight = temp2;

				if(temp1.left!=null){
					q.add(temp1.left);
				}
				if(temp1.right!=null){
					q.add(temp1.right);
				}
				count--;
			}
		}


	}


	public void testConnection(Node root){
		if(root==null){
			return;
		}
		if(root.nextRight==null){
			System.out.println("sibling of"+root.data+"is"+"Null");
		}
		else{
			System.out.println("sibling of "+root.data+"is "+root.nextRight.data);
		}
		testConnection(root.left);
		testConnection(root.right);
	}


	public static void main(String s[]){
		connect c = new connect();
		Node root = new Node('A');
		root.left = new Node('B');
		root.right = new Node('C');
		root.left.left = new Node('D');
		root.left.right = new Node('E');
		root.right.right = new Node('F');

		c.bfsVariant(root);

		c.testConnection(root);
	}
}