  class Bank {
private:
    vector<long long> balances;
public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > balances.size() || account2 > balances.size() || balances[account1 - 1] < money) {
            return false;
        }
        balances[account1 - 1] -= money;
        balances[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > balances.size()) {
            return false;
        }
        balances[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > balances.size() || balances[account - 1] < money) {
            return false;
        }
        balances[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
