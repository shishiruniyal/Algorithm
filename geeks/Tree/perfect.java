import java.util.*;
class Node{
	int data;
	Node left,right;
	Node(int value){
		data = value;
		left = right = null;
	}
}

class perfect{
	void level_order(Node root,int n){
		int a[] = new int[n];
		int i = 0;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while(!q.isEmpty()){
			Node temp = q.poll();
			a[i] = temp.data;
			i++;
			if(temp.left!=null)
				q.add(temp.left);
			if(temp.right!=null)
				q.add(temp.right);
		}
		//System.out.println(Arrays.toString(a));
		int k = height(root);
		System.out.println("Height is "+k);
		//System.out.print(a[k]+" ");
		for(i = n-1;i>=0;i--){
			int r = i;
			int l = i-((int)Math.pow(2,k)-1);
			// System.out.println("l = "+l+" r= "+r);
			i=l;
			while(l<r&&l>=0){
				System.out.print(a[l]+" "+a[r]+" ");
				l++;
				r--;
			}
			if(l==r){
				System.out.print(a[l]+" ");
			}
			k--;
		}
	}
int height(Node root){
	if(root==null){
		return -1;
	}
	int lh = height(root.left)+1;
	int rh = height(root.right)+1;

	return lh>rh?lh:rh;
}
	void level_order2(Node root){
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);

		while(!q.isEmpty()){
			Node temp1 = q.poll();
			Node temp2 = null;
			System.out.print(temp1.data+" ");
			if(!q.isEmpty()){
				temp2 = q.poll();
				System.out.print(temp2.data+" ");
			}

			if(temp1.left!=null){
				q.add(temp1.left);
			}
			if(temp2!=null&&temp2.right!=null){
				q.add(temp2.right);
			}
			if(temp1.right!=null){
				q.add(temp1.right);
			}
			if(temp2!=null&&temp2.left!=null){
				q.add(temp2.left);
			}
		}
		System.out.println();
	}

	void level_order_modified(Node root){
		Queue<Node> q = new LinkedList<Node>();
		Stack<Integer> st = new Stack<Integer>();
		st.add(root.data);
		if(root.left!=null){
			q.add(root.right);
			q.add(root.left);
		}

		while(!q.isEmpty()){
			Node temp1 = q.poll();
			Node temp2 = null;
			st.add(temp1.data);
			if(!q.isEmpty()){
				temp2 = q.poll();
				st.add(temp2.data);
			}

			if(temp1.left!=null){
				q.add(temp1.left);
			}
			if(temp2!=null&&temp2.right!=null){
				q.add(temp2.right);
			}
			if(temp1.right!=null){
				q.add(temp1.right);
			}
			if(temp2!=null&&temp2.left!=null){
				q.add(temp2.left);
			}
		}
		System.out.println();
		while(!st.empty()){
			System.out.print(st.pop()+" ");
		}
	}
	public static void main(String[] args) {
		Node root = new Node(1);

		root.left = new Node(2);
		root.right = new Node(3);

		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);

		root.left.left.left = new Node(8);
		root.left.left.right = new Node(9);
		root.left.right.left = new Node(10);
		root.left.right.right = new Node(11);

		root.right.left.left = new Node(12);
		root.right.left.right = new Node(13);

		root.right.right.right = new Node(15);
		root.right.right.left = new Node(14);


		perfect p =new perfect();
		p.level_order_modified(root);
		//p.level_order(root,15);

	}
}