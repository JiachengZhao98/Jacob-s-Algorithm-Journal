#include "iostream"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

class fileSystem {

private:
    unordered_map<string, string> filename_size;
    map<int, set<string>> size_filename;
    map<string, pair<int, set<string>>> user_filename;

public:

    fileSystem() {
    }

    bool ADD_USER(string userId, string capacity) {
        if (user_filename.count(userId) != 0) return false;
        set<string> filenames;
        user_filename.insert(make_pair(userId, make_pair(stoi(capacity), filenames)));
        return 1;
    }

    string ADD_FILE_BY(string userId, string name, string size) {
        int size_int = stoi(size);
        if (size_int > user_filename[userId].first) return "";
        if (filename_size.count(name) != 0) return "";
        filename_size[name] = size;
        size_filename[size_int].insert(name);
        user_filename[userId].first -= size_int;
        user_filename[userId].second.insert(name);
        return to_string(user_filename[userId].first);
    }

    string MERGE_USER(string userId1, string userId2) {
        if (userId1 == userId2 || user_filename.count(userId1) == 0 || user_filename.count(userId2) == 0) return "";
        int cap = user_filename[userId2].first;
        for (auto a : user_filename[userId2].second) {
            user_filename[userId1].second.insert(a);
        }
        user_filename[userId1].first += cap;
        user_filename.erase(userId2);
        return to_string(user_filename[userId1].first);

    }

    bool ADD_FILE(string name, string size) {
        if (filename_size.count(name) != 0) {
            return false;
        }
        filename_size[name] = size;
        size_filename[stoi(size)].insert(name);
        return true;
    }

    string GET_FILE_SIZE(string name) {
        if (filename_size.count(name) == 0) return "";
        return filename_size[name];
    }

    string DELETE_FILE(string name) {
        if (filename_size.count(name) == 0) return "";
        string res = filename_size[name];
        filename_size.erase(name);
        int size = stoi(res);
        size_filename[size].erase(name);
        return res;
    }

    string GET_N_LARGEST(string prefix, string n) {
        for (auto a : n) {
            if (!isdigit(a)) return "";
        }
        int num = stoi(n);
        string ans;
        if (num == 0) return ans;
        for (auto iter = size_filename.rbegin(); iter != size_filename.rend(); ++iter) {
            if (num == 0) break;
            for (auto str : iter->second) {
                if (str.starts_with(prefix)) {
                    ans += str + '(' + filename_size[str] + ')' + ", ";
                }
                num--;
                if (num == 0) break;
            }
        }
        ans.pop_back();
        ans.pop_back();
        return ans;
    }
};

class bankSystem {

private:

public:

    unordered_map<string, string> accountId_balance;
    map<int, set<string>> amount_accountId;
    unordered_map<string, int> accountId_amount;
    unordered_map<string, vector<string>> transferId_timeAndAmountAndSourceId;
    int transferCount;

    bankSystem() {
        this->transferCount = 0;
    }

    bool CREATE_ACCOUNT(string timestamp, string accountId) {
        if (accountId_balance.find(accountId) != accountId_balance.end()) {
            return false;
        }
        accountId_balance.insert(make_pair(accountId, "0"));
        return 1;
    }

    string DEPOSIT(string timestamp, string accountId, string amount) {
        if (accountId_balance.find(accountId) == accountId_balance.end()) return "";
        int cur_bal = stoi(amount);
        int trans_amount = accountId_amount[accountId];
        accountId_amount[accountId] += cur_bal;
        amount_accountId[trans_amount].erase(accountId);
        amount_accountId[accountId_amount[accountId]].insert(accountId);
        cur_bal += stoi(accountId_balance[accountId]);
        accountId_balance[accountId] = to_string(cur_bal);
        return to_string(cur_bal);
    }

    string PAY(string timestamp, string accountId, string amount) {
        if (accountId_balance.find(accountId) == accountId_balance.end() ||
            stoi(accountId_balance[accountId]) < stoi(amount)) {
                return "";
            }
        int cur_bal = stoi(accountId_balance[accountId]);
        int trans_amount = accountId_amount[accountId];
        accountId_amount[accountId] += stoi(amount);
        amount_accountId[trans_amount].erase(accountId);
        amount_accountId[accountId_amount[accountId]].insert(accountId);
        cur_bal -= stoi(amount);
        accountId_balance[accountId] = to_string(cur_bal);
        return to_string(cur_bal);
    }

    string TOP_ACTIVITY(string timestamp, string n) {
        string res;
        int num = stoi(n);
        for (auto iter = amount_accountId.rbegin(); iter != amount_accountId.rend(); ++iter) {
            if (num == 0) break;
            for (auto a : iter->second) {
                res += a + '(' + to_string(iter->first) + "), ";
                num--;
                if (num == 0) break;
            }
        }
        res.pop_back();
        res.pop_back();
        return res;
    }

    string TRANASFER(string timestamp, string sourceAccountId, string targetAccountId, string amount) {
        if (sourceAccountId == targetAccountId || accountId_balance.find(sourceAccountId) == accountId_balance.end()
            || accountId_balance.find(targetAccountId) == accountId_balance.end()) {
                return "";
            }
        int sourceAccountBalance = stoi(accountId_balance[sourceAccountId]), transAmount = stoi(amount);
        if (sourceAccountBalance < transAmount) return "";
        transferCount++;
        vector<string> vec;
        string transferId = "transfer" +to_string(transferCount);
        vec.push_back(timestamp);
        vec.push_back(amount);
        vec.push_back(sourceAccountId);
        vec.push_back(targetAccountId);
        transferId_timeAndAmountAndSourceId[transferId] = vec;
        return transferId;
    }

    bool ACCEPT_TRANASFER(string timestamp, string accountId, string transferId) {
        if (transferId_timeAndAmountAndSourceId.find(transferId) == transferId_timeAndAmountAndSourceId.end()
            || accountId_balance.find(accountId) == accountId_balance.end()) return false;
        vector<string> vec = transferId_timeAndAmountAndSourceId[transferId];
        int time = stoi(vec[0]);
        if (stoi(timestamp) - time > 86400000) {
            transferId_timeAndAmountAndSourceId.erase(transferId);
            return false;
        }
        if (accountId != vec[3]) return false;
        //int transferAmount = stoi(vec[1]);
        string sourceId = vec[2];
        string deposit = DEPOSIT(timestamp, accountId, vec[1]);
        string pay = PAY(timestamp, sourceId, vec[1]);
        transferId_timeAndAmountAndSourceId.erase(transferId);
        return 1;
    }
};

class bankSys2 {

private:
    // level 1
    unordered_map<string, pair<int, int>> accountID_balance_transAmount;
    unordered_map<string, map<string, int>> history;

    // level 2
    map<int, set<string>> transAmount_accountId;

    // level 3
    unordered_map<string, vector<string>> payID_timeAccountIDAmount;
    int payment = 0;

    // level 4
    unordered_map<string, set<string>> accountID_paymentId;


public:
    bankSys2() {
    }

    bool CREATE_ACCOUNT(string timestamp, string accountId) {
        if (accountID_balance_transAmount.find(accountId) != accountID_balance_transAmount.end()) {
            return false;
        }
        auto temp = pair<int, int>(0,0);
        accountID_balance_transAmount[accountId] = temp;
        transAmount_accountId[0].insert(accountId);
        map<string, int> mp;
        mp[timestamp] = 0;
        history[accountId] = mp;
        return 1;
    }

    string DEPOSIT(string timestamp, string accountId, string amount) {
        if (accountID_balance_transAmount.find(accountId) == accountID_balance_transAmount.end()) {
            return "";
        }
        int amount_num = stoi(amount);
        accountID_balance_transAmount[accountId].first += amount_num;
        history[accountId][timestamp] = accountID_balance_transAmount[accountId].first;
        return to_string(accountID_balance_transAmount[accountId].first);
    }

    string TRANSFER(string timestamp, string sourceAccountId, string targetAccountId, string amount) {
        if (sourceAccountId == targetAccountId || accountID_balance_transAmount.find(sourceAccountId) == accountID_balance_transAmount.end()
            || accountID_balance_transAmount.find(targetAccountId) == accountID_balance_transAmount.end()) {
                return "";
            }
        int cur_fund_source = accountID_balance_transAmount[sourceAccountId].first, amount_num = stoi(amount);
        if (cur_fund_source < amount_num) return "";

        // transfer from source
        int cur_trans_amount_source = accountID_balance_transAmount[sourceAccountId].second;
        accountID_balance_transAmount[sourceAccountId].first -= amount_num;
        history[sourceAccountId][timestamp] = accountID_balance_transAmount[sourceAccountId].first;
        accountID_balance_transAmount[sourceAccountId].second += amount_num;
        transAmount_accountId[cur_trans_amount_source].erase(sourceAccountId);
        transAmount_accountId[accountID_balance_transAmount[sourceAccountId].second].insert(sourceAccountId);

        // trnasfer to target
        accountID_balance_transAmount[targetAccountId].first += amount_num;
        history[targetAccountId][timestamp] = accountID_balance_transAmount[targetAccountId].first;

        return to_string(accountID_balance_transAmount[sourceAccountId].first);
    }

    string TOP_SPENDERS(string timestamp, string n) {
        string res;
        int count = stoi(n);
        for (auto iter = transAmount_accountId.rbegin(); iter != transAmount_accountId.rend(); ++iter) {
            if (count == 0) break;
            for (auto a : iter->second) {
                res += a + '(' + to_string(iter->first) + "), ";
                count--;
                if (count == 0) break;
            }
        }
        res.pop_back();
        res.pop_back();
        return res;
    }

    string PAY(string timestamp, string accountId, string amount) {
        if (accountID_balance_transAmount.find(accountId) == accountID_balance_transAmount.end()) return "";
        int cur_fund = accountID_balance_transAmount[accountId].first, amount_num = stoi(amount);
        if (cur_fund < stoi(amount)) return "";
        payment++;
        string paymentID = "payment" + to_string(payment);

        int cur_trans_amount = accountID_balance_transAmount[accountId].second;
        accountID_balance_transAmount[accountId].first -= amount_num;
        accountID_balance_transAmount[accountId].second += amount_num;
        transAmount_accountId[cur_trans_amount].erase(accountId);
        transAmount_accountId[accountID_balance_transAmount[accountId].second].insert(accountId);
        history[accountId][timestamp] = accountID_balance_transAmount[accountId].first;
        vector<string> vec = {timestamp, accountId, amount};
        payID_timeAccountIDAmount[paymentID] = vec;
        accountID_paymentId[accountId].insert(paymentID);
        return paymentID;
    }

    string GET_PAYMENT_STATUS(string timestamp, string accountId, string payment) {
        if (payID_timeAccountIDAmount.find(payment) == payID_timeAccountIDAmount.end()) return "";
        if (accountID_balance_transAmount.find(accountId) == accountID_balance_transAmount.end()) return "";
        if (payID_timeAccountIDAmount[payment][1] != accountId) return "";
        int time = stoi(payID_timeAccountIDAmount[payment][0]);
        if (stoi(timestamp) - time < 86400000) return "IN_PROGRESS";
        else {
            int cash = stoi(payID_timeAccountIDAmount[payment][2]) * 0.02;
            accountID_balance_transAmount[accountId].first += cash;
            accountID_paymentId[accountId].erase(payment);
            history[accountId][timestamp] = accountID_balance_transAmount[accountId].first;
        }
    }

    bool MERGE_ACCOUNTS(string timestamp, string accountId1, string accountId2) {
        if (accountId1 == accountId2
            || accountID_balance_transAmount.find(accountId1) == accountID_balance_transAmount.end()
            || accountID_balance_transAmount.find(accountId2) == accountID_balance_transAmount.end()) return 0;

        int id2_bal = accountID_balance_transAmount[accountId2].first;
        int id2_transAmount = accountID_balance_transAmount[accountId2].second;
        int id1_bal = accountID_balance_transAmount[accountId1].first;
        int id1_transAmount = accountID_balance_transAmount[accountId1].second;
        // erase id2
        accountID_balance_transAmount.erase(accountId2);
        transAmount_accountId[id2_transAmount].erase(accountId2);

        accountID_balance_transAmount[accountId1].first += id2_bal;
        accountID_balance_transAmount[accountId1].second += id2_transAmount;
        transAmount_accountId[id1_transAmount].erase(accountId1);
        transAmount_accountId[accountID_balance_transAmount[accountId1].second].insert(accountId1);
        for (auto a : accountID_paymentId[accountId2]) {
            payID_timeAccountIDAmount[a][1] = accountId1;
            accountID_paymentId[accountId1].insert(a);
        }
        accountID_paymentId.erase(accountId2);
        return 1;
    }

    string GET_BALANCE(string timestamp, string accountId, string timeAt) {
        if (accountID_balance_transAmount.find(accountId) == accountID_balance_transAmount.end()) return "";
        vector<string> paymentId_received;
        for (auto a : accountID_paymentId[accountId]) {
            vector<string> cur = payID_timeAccountIDAmount[a];
            int time = stoi(cur[0]);
            if (stoi(timeAt) - time > 86400000) {
                int cash = stoi(cur[2]) * 0.02;
                accountID_balance_transAmount[accountId].first += cash;
                paymentId_received.push_back(a);
            }
        }
        for(auto paymentId : paymentId_received) {
            accountID_paymentId[accountId].erase(paymentId);
        }
        return to_string(accountID_balance_transAmount[accountId].first);
    }

};


class database {
private:
  // level 1
  unordered_map<string, map<string, string>> records;

  // level 2
  // no additional data structure

  // level 3
  map<int, unordered_map<string, unordered_set<string>>> ttl_keyField;
  map<pair<string, string>, int> keyField_TTL;

  // level 4
  struct backup {
    unordered_map<string, map<string, string>> records;
    map<pair<string, string>, int> keyField_TTL;
  };
  map<int, backup> time_backup;


public:
  string SET(string key, string field, string value) {
    records[key][field] = value;
    return "";
  }

  string GET(string key, string field) {
    if (records.find(key) == records.end() || records[key].find(field) == records[key].end()) {
      return "";
    }
    return records[key][field];
  }

  bool DELETE(string key, string field) {
    if (records.find(key) == records.end() || records[key].find(field) == records[key].end()) {
      return 0;
    }
    records[key].erase(field);
    return 1;
  }

  string SCAN(string key) {
    string res;
    if (records.find(key) == records.end()) {
      return res;
    }
    for (auto a : records[key]) {
      res += a.first + '(' + a.second + "), ";
    }
    res.pop_back();
    res.pop_back();
    return res;
  }

  string SCAN_BY_PREFIX(string key, string prefix) {
    string res;
    if (records.find(key) == records.end()) {
      return res;
    }
    for (auto a : records[key]) {
      if (a.first.starts_with(prefix)) {
        res += a.first + '(' + a.second + "), ";
      }
    }
    res.pop_back();
    res.pop_back();
    return res;
  }

// with timestamp


  string SET_AT(string key, string field, string value, string timestamp) {
    checkTTL(timestamp);
    records[key][field] = value;
    return "";
  }

  string SET_AT_WITH_TTL(string key, string field, string value, string timestamp, string ttl) {
    checkTTL(timestamp);
    records[key][field] = value;
    int time = stoi(timestamp) + stoi(ttl);
    if (keyField_TTL.find(make_pair(key, field)) != keyField_TTL.end()) {
        int cur_ttl = keyField_TTL[make_pair(key, field)];
        keyField_TTL[make_pair(key, field)] = time;
        ttl_keyField[cur_ttl][key].erase(field);
        ttl_keyField[time][key].insert(field);
    }
    else {
        ttl_keyField[time][key].insert(field);
        keyField_TTL[make_pair(key, field)] = time;
    }
    return "";
  }

  string GET_AT(string key, string field, string timestamp) {
    checkTTL(timestamp);
    if (records.find(key) == records.end() || records[key].find(field) == records[key].end()) {
      return "";
    }
    return records[key][field];
  }

  bool DELETE_AT(string key, string field, string timestamp) {
    checkTTL(timestamp);
    if (records.find(key) == records.end() || records[key].find(field) == records[key].end()) {
      return 0;
    }
    records[key].erase(field);
    return 1;
  }

  string SCAN_AT(string key, string timestamp) {
    checkTTL(timestamp);
    string res;
    if (records.find(key) == records.end()) {
      return "";
    }
    if (records[key].empty()) return "";
    for (auto a : records[key]) {
      res += a.first + '(' + a.second + "), ";
    }
    res.pop_back();
    res.pop_back();
    return res;
  }

  string SCAN_BY_PREFIX_AT(string key, string prefix, string timestamp) {
    checkTTL(timestamp);
    string res;
    if (records.find(key) == records.end()) {
      return "";
    }
    if (records[key].empty()) return "";
    for (auto a : records[key]) {
      if (a.first.starts_with(prefix)) {
        res += a.first + '(' + a.second + "), ";
      }
    }
    res.pop_back();
    res.pop_back();
    return res;
  }

  void checkTTL(string timestamp) {
    int time = stoi(timestamp);
    vector<int> rec;
    if (ttl_keyField.empty()) return;
    for (auto a : ttl_keyField) {
        if (a.first <= time) {
            for (auto iter : a.second) {
                string key = iter.first;
                for (auto field : iter.second) {
                    records[key].erase(field);
                    keyField_TTL.erase(make_pair(key, field));
                }
            }
            rec.push_back(a.first);
        }
      else break;
    }
    for (auto a : rec) {
      ttl_keyField.erase(a);
    }
  }
  string BACKUP(string timestamp) {
    checkTTL(timestamp);
    int time = stoi(timestamp);
    map<pair<string, string>, int> keyField_TTL_backup;
    keyField_TTL_backup = keyField_TTL;
    for (auto iter = keyField_TTL_backup.begin(); iter != keyField_TTL_backup.end(); ++iter) {
      iter->second -= time;
    }
    time_backup.insert(make_pair(time, backup{records, keyField_TTL_backup}));
    return to_string(records.size());
  }

  string RESTORE(string timestamp, string timeToRestore) {
    int time = stoi(timeToRestore), cur_time = stoi(timestamp);
    auto backup = time_backup.begin();
    for (auto iter = time_backup.begin(); iter != time_backup.end(); ++iter) {
      if (iter->first > time) {
        iter = prev(iter);
        backup = iter;
        break;
      }
    }
    records = backup->second.records;
    ttl_keyField.clear();
    keyField_TTL.clear();
    for (auto a : backup->second.keyField_TTL) {
      a.second += cur_time;
      keyField_TTL[make_pair(a.first.first, a.first.second)] = a.second;
    }
    for (auto a : keyField_TTL) {
      ttl_keyField[a.second][a.first.first].insert(a.first.second);
    }
    return "";
  }

};


int main() {
    //fileSystem fs;
    // cout<<fs.ADD_USER("user1", "200")<<" ";
    // cout<<fs.ADD_USER("user1", "100")<<" ";
    // cout<<fs.ADD_FILE_BY("user1", "/dir/file.med", "50")<<" ";
    // cout<<fs.ADD_FILE_BY("user1", "/file.big", "140")<<" ";
    // cout<<fs.ADD_FILE_BY("user1", "/dir/file.small", "20")<<" ";
    // cout<<fs.ADD_FILE("/dir/admin_file", "300")<<" ";
    // cout<<fs.ADD_USER("user2", "110")<<" ";
    // cout<<fs.ADD_FILE_BY("user2", "/dir/file.med", "50")<<" ";
    // cout<<fs.ADD_FILE_BY("user2", "/new_file", "50")<<" ";
    // cout<<fs.MERGE_USER("user1", "user2")<<endl;
    // cout<<fs.ADD_FILE("/dir/file1.txt", "5")<<endl;
    // cout<<fs.ADD_FILE("/dir/file2", "20")<<endl;
    // cout<<fs.ADD_FILE("/dir/deeper/file3.mov", "9")<<endl;
    // cout<<fs.GET_N_LARGEST("/dir", "2")<<endl;
    // cout<<fs.GET_N_LARGEST("/dir/file", "3")<<endl;
    // cout<<fs.GET_N_LARGEST("/another_dir", "file.txt")<<endl;
    // cout<<fs.ADD_FILE("/big_file.mp4", "20")<<endl;
    // cout<<fs.GET_N_LARGEST("/", "2")<<endl;

    //bankSystem bs;
    // cout<<bs.CREATE_ACCOUNT("1", "account1")<<" ";
    // cout<<bs.CREATE_ACCOUNT("2", "account2")<<" ";
    // cout<<bs.CREATE_ACCOUNT("3", "account3")<<" ";
    // cout<<bs.DEPOSIT("4", "account1", "2000")<<" ";
    // cout<<bs.DEPOSIT("5", "account2", "3000")<<" ";
    // cout<<bs.DEPOSIT("6", "account3", "4000")<<" ";
    // cout<<bs.TOP_ACTIVITY("7", "3")<<" ";
    // cout<<bs.PAY("8", "account1", "1500")<<" ";
    // cout<<bs.PAY("9", "account2", "250")<<" ";
    // cout<<bs.DEPOSIT("10", "account3", "250")<<" ";
    // cout<<bs.TOP_ACTIVITY("11", "3")<<" ";

    // cout<<bs.CREATE_ACCOUNT("1", "account1")<<" ";
    // cout<<bs.CREATE_ACCOUNT("2", "account2")<<" ";
    // cout<<bs.DEPOSIT("3", "account1", "2000")<<" ";
    // cout<<bs.DEPOSIT("4", "account2", "3000")<<" ";
    // cout<<bs.TRANASFER("5", "account1", "account2", "5000")<<" ";
    // cout<<bs.TRANASFER("16", "account1", "account2", "1000")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("20", "account1", "transfer1")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("21", "non", "transfer1")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("22", "account1", "transfer2")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("25", "account2", "transfer1")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("30", "account2", "transfer1")<<" ";
    // cout<<bs.TRANASFER("40", "account1", "account2", "1000")<<" ";
    // cout<<bs.ACCEPT_TRANASFER("100000000", "account2", "transfer3");
    // cout<<bs.TRANASFER("4000000", "account1", "account1", "1000")<<" ";


    //bankSys2 bs2;
    // cout<<bs2.CREATE_ACCOUNT("1", "account1")<<" ";
    // cout<<bs2.CREATE_ACCOUNT("2", "account2")<<" ";
    // cout<<bs2.DEPOSIT("3", "account1", "2000")<<" ";
    // cout<<bs2.DEPOSIT("4", "account2", "2000")<<" ";
    // cout<<bs2.PAY("5", "account2", "3000")<<" ";
    // cout<<bs2.TRANSFER("6", "account1", "account2", "500")<<" ";
    // cout<<bs2.MERGE_ACCOUNTS("7", "account1", "non")<<" ";
    // cout<<bs2.MERGE_ACCOUNTS("8", "account1", "account1")<<" ";
    // cout<<bs2.MERGE_ACCOUNTS("9", "account1", "account2")<<" ";
    // cout<<bs2.DEPOSIT("10", "account1", "100")<<" ";
    // cout<<bs2.DEPOSIT("11", "account2", "100")<<" ";
    // cout<<bs2.GET_PAYMENT_STATUS("12", "account2", "payment1")<<" ";
    // cout<<bs2.GET_PAYMENT_STATUS("13", "account1", "payment1")<<" ";
    // cout<<bs2.GET_BALANCE("14", "account2", "1")<<" ";
    // cout<<bs2.GET_BALANCE("15", "account2", "9")<<" ";

    database db;
    // cout<<db.SET_AT("A", "BC", "E", "1")<<" ";
    // cout<<db.SET_AT_WITH_TTL("X", "Y", "z", "2", "15")<<" ";
    // cout<<db.GET_AT("X", "Y", "3")<<" ";
    // cout<<db.SET_AT_WITH_TTL("A", "D", "E", "4", "10")<<" ";
    // cout<<db.SCAN_AT("A", "13")<<" ";
    // cout<<db.SCAN_AT("X", "16")<<" ";
    // cout<<db.SCAN_AT("X", "17")<<" ";
    // cout<<db.DELETE_AT("X", "Y", "20")<<" ";
    cout<<db.SET_AT_WITH_TTL("A", "B", "C", "1", "10")<<" ";
    cout<<db.BACKUP("3")<<" ";
    cout<<db.SET_AT("A", "D", "E", "4")<<" ";
    cout<<db.BACKUP("5")<<" ";
    cout<<db.DELETE_AT("A", "B", "8")<<" ";
    cout<<db.BACKUP("9")<<" ";
    cout<<db.RESTORE("10", "7")<<" ";
    cout<<db.BACKUP("11")<<" ";
    cout<<db.SCAN_AT("A", "15")<<" ";
    cout<<db.SCAN_AT("A", "16")<<" ";
    cout<<endl;
    return 0;

}
