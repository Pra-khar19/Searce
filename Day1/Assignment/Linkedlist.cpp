void solve(TreeNode* head)
{
    TreeNode* curr=head;
    while(curr!=NULL)
    {
        cout<<curr->val<<endl;        //printing the linkedlist with the address
        curr=curr->next;
    }
}