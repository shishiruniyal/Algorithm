import java.util.LinkedList;
import java.util.Queue;
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


	public static void main(String s[]){
		Node root=new Node(1);
		root.left=new Node(2); 
		root.right=new Node(3);	
		root.left.left=new Node(4);
		root.left.right=new Node(5);
		width w = new width();

		System.out.println("width of the tree is "+ w.widthCalculate(root));
	}

}