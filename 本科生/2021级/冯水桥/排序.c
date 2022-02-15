#include <stdio.h>
#include <malloc.h>
void mp(int *arr,int n)//√∞≈› 
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	return ;
}
void sz(int *a,int n)//—°‘Ò 
{
	int i,j,irig=n-1;
	for(j=1;j<n;j++)
{
	int min=a[0];
	int index=0;
	for(i=1;i<=irig;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			index=i;
		}
	}
	int temp=a[index];
	a[index]=a[irig];
	a[irig]=temp;
	irig--;
}
 } 
 
 void cr(int *a,int n)//≤Â»Î 
 {
 	int i,j;
 	for(i=1;i<n;i++)
 	{
 		int temp=a[i];
 		for(j=i-1;j>=0;j--)
 		{
 			if(a[j]>=temp)
 			{
 				a[j+1]=temp;
 				break;
			 }
			 a[j+1]=a[j];
			 if(0==j)
			 {
			 	a[0]=temp;
			 }
		 }
	 }
 }
 void ks1(int *a,int start,int end)//◊Û”“ 
 {
 	if(start>=end)
 	{
 		return;
	 }
 	int key=a[start];
 	int temp,left=start,right=end;
 	while(left<right)
 	{
 		 
		 while(right>left&&a[right]<=key)
		 {
		 	right--;
		 }
		 while(left<right&&a[left]>=key)
 		{
 			left++;
		 }
		 if(left<right,right)
		 {
		 	temp=a[left];
		 	a[left]=a[right];
			a[right]=temp;
		 }
	}
	temp=a[left];
	a[left]=a[start];
	a[start]=temp;
	int meet=left;
	ks1(a,start,meet-1);
	ks1(a,meet+1,end);	 
 }
 void ks2(int*a,int start,int end)//Õ⁄ø” 
 {
 	if(start>=end)
 	{
 		return;
	 }
	int key=a[start];
	int left=start;
	int right=end;
	while(left<right)
	{
	while(left<right&&a[right]<=key)
	{
		right--;
	}
	a[left]=a[right];
	while(left<right&&a[left]>=key)
	{
		left++;
	}
	a[right]=a[left];
  } 
  a[left]=key;
  int meet=left;
  ks2(a,start,meet-1);
  ks2(a,meet+1,end);
}
void ks3(int *a,int start,int end)//«∞∫Û 
{
	if(start>=end)
	{
		return;
	}
	int temp=0;
	int cur=start;
	int prev=start-1;
	int key=a[end];
	while(cur<end)
	{
		if(a[cur]>+key&&++prev!=cur)
		{
			temp=a[prev];
			a[prev]=a[cur];
			a[cur]=temp;
		}
		cur++;
	}
	++prev; 
	temp=a[end];
	a[end]=a[prev];
	a[prev]=temp;
	ks3(a,start,prev-1);
	ks3(a,prev+1,end);
}
void sort(int *a,int left,int right)
{
	void gb();
	if(left>=right)
	{
		return;
	}
	int mid=(left+right)/2;
	sort(a,left,mid);
	sort(a,mid+1,right);
	gb(a,left,mid,right);
}
void gb(int *a,int left,int mid,int right)
{
	int *temp=(int*)malloc(sizeof(int)*(right-left+1));
	int i=left,k=left,j=mid+1;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			j++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++; 
	}
	while(j<=right)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=left;i<=right;i++)
	{
		a[i]=temp[i];
	}
	free(temp);
}
int main()
{
	int arr[8]={3,7,9,2,5,6,8,1};
	int i;
	sort(arr,0,7);
	for(i=0;i<8;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
 } 
