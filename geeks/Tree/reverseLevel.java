import java.util.*;
class Node{
	int data;
	Node left,right;

	Node(int value){
		data = value;
		left = right = null;
	}
}

class reverse{
	void printReverse(Node root){
		Stack<Integer> st = new Stack<Integer>();
		Queue<Node> q = new LinkedList<Node>();

		q.add(root);

		while(!q.isEmpty()){
			Node temp = q.poll();
			st.push(temp.data);
			if(temp.right!=null){
				q.add(temp.right);
			}
			if(temp.left!=null){
				q.add(temp.left);
			}
		}
		while(!st.empty()){
			System.out.print(st.pop()+" ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		
		reverse re = new reverse();
		re.printReverse(root);
	}
}