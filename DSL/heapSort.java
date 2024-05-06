import java.util.ArrayList;
class heapSort{
    ArrayList<Integer> arr = new ArrayList<Integer>();

    public void upheapify(int child){

        while(child>0){
            int parent=(child-1)/2;
            if(arr.get(parent)>arr.get(child)){
                int temp=arr.get(parent);
                arr.set(parent,arr.get(child));
                arr.set(child,temp);
                child=parent;
            }
            else break;
        }
    }

    public void downheapify(int parent){
        while(parent<arr.size()){

            int lc=(2*parent)+1;
            if(lc>=arr.size()) break;
            int rc=(2*parent)+2;
            int smallestidx=(arr.get(lc)<arr.get(parent))? lc:parent;
            if(rc<arr.size()) smallestidx=(arr.get(rc)<arr.get(smallestidx))? rc:smallestidx;

            if(smallestidx==parent) break;
            else{
                int temp=arr.get(smallestidx);
                arr.set(smallestidx,arr.get(parent));
                arr.set(parent,temp);
                parent=smallestidx;
            }
        }
    }

    public void push(int ele){
        arr.add(ele);
        int n=arr.size()-1;
        upheapify(n);
    }
    public void pop(){
        arr.set(0,arr.get(arr.size()-1));
        arr.remove(arr.size()-1);
        downheapify(0);

    }
    public void peek(){
        if(arr.size()==0) System.out.println("Heap is empty");
        else System.out.println(arr.get(0));
    }

    public void display(){
        if(arr.size()==0) System.out.println("Heap is empty");
        else{
            System.out.println(arr);
        }
    }

    public static void main(String[] args){
        heapSort hp=new heapSort();
        hp.push(200);
        hp.push(30);
        hp.push(20);
        hp.push(45);
        hp.push(50);
        hp.push(300);
        hp.display();
        hp.peek();
        hp.pop();
        hp.peek();
        hp.display();
    }


}