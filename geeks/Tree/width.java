import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
class Node{
	Node left,right;
	int value;

	Node(int val){
		value = val;
		left = null;
		right = null;
	}
}


class width{

	public int widthCalculate(Node root){
		int max = 0;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		int count = 0,outcount = 1;
		while(!q.isEmpty()){
			if(outcount>max){
				max = outcount;
			}
			while(outcount!=0){
				Node temp = q.poll();
				if(temp.left!=null){
					q.add(temp.left);
					count++;
				}
				if(temp.right!=null){
					q.add(temp.right);
					count++;
				}
				outcount--;
			}
			outcount = count;
			count=0;
		}

		return max;
	}


	void PostOrder(Node root){
		if(root==null){
			System.out.println("Empty tree");
		}
		Stack<Node> st = new Stack<Node>();

		st.push(root);
		root = root.left;

		while(!st.empty()){
			while(root!=null){
				st.push(root);
				root = root.left;
			}
			Node temp = st.peek();
			if(temp.right==null){
				temp = st.pop();
				System.out.print(temp.value+" ");
				while(!st.empty()&&st.peek().right==temp){
					temp = st.pop();
					System.out.print(temp.value+" ");
				}
			}
			if(!st.empty()){
				root = st.peek().right;
			}
		}
	}

	public static void main(String s[]){
		Node root = new Node(1);
		
		root.right = new Node(3);
		
		root.right.right = new Node(7);
		root.right.right.right = new Node(10);
		root.right.right.right.right = new Node(11);
		root.right.right.right.right.right = new Node(12);
		width w = new width();

		System.out.println("width of the tree is "+ w.widthCalculate(root));

		
		w.widthCalculate(root);	

		System.out.println("PostOrder traversal is");

		w.PostOrder(root);
	}

}