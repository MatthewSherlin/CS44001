// Mikhail Nesterenko modified by Matthew Sherlin
// 11/22/2014

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector; using std::string; using std::getline;
using std::cout; using std::cin; using std::endl;

class Memento;

// receiver
class Document {
public:

   Document(const vector <string> & lines={}): lines_(lines){}

   // actions
   void insert(int line, const string &str) {
      const int index = line-1;
      if (index <= lines_.size())
	 lines_.insert(lines_.begin() + index, str); 
      else
	 cout << "line out of range" << endl; 
   }

   string remove(int line) {
      const int index = line-1;
      string deletedLine="";
      if(index < lines_.size()){
	 deletedLine = lines_[index];
	 lines_.erase(lines_.begin() + index); 
      }else cout << "line out of range" << endl; 
      return deletedLine;
   } 

   void show() {
      for(int i = 0; i < lines_.size(); ++i)
	 cout << i + 1 << ". " << lines_[i] << endl; 
   }

private:
   vector<string> lines_; 
}; 

// abstract command
class Command{
public:
   Command(Document *doc) : doc_(doc){}
   virtual void execute() = 0; 
   virtual void unexecute() = 0; 
   virtual ~Command(){}
   virtual Command* revert()= 0;
   virtual void show() = 0;
protected:
   Document *doc_; 
}; 

// two concrete commands
class InsertCommand : public Command {
public:
   InsertCommand(Document *doc, int line, const string &str): 
      Command(doc), line_(line),  str_(str) {}
   void execute() override { doc_->insert(line_, str_);}
   void unexecute() override {doc_->remove(line_);}
   Command* revert() override{ return new InsertCommand(doc_, line_, str_);}
   void show() override{ cout << "Line Number: " << line_ << '\n'; cout << "String modified: " << str_ << "\n\n";}
private:
   int line_; 
   string str_; 
}; 


class EraseCommand : public Command {
public:
   EraseCommand(Document *doc, int line): 
      Command(doc), line_(line), str_("") {}
   void execute() override {str_ = doc_->remove(line_);}
   void unexecute() override {doc_-> insert(line_, str_);}
   Command* revert() override{ return new EraseCommand(doc_, line_);}
   void show() override{ cout << "Line Number: " << line_ << '\n'; cout << "String modified: " << str_ << "\n\n";}
	
private:
   int line_;
   string str_;
};

// client
class DocumentWithHistory : public Document{
public:
   DocumentWithHistory(const vector<string> & text={}) : doc_(text){}

  ~DocumentWithHistory(){
  		Command *ptr;
  		while(!doneCommands_.empty()){
  			ptr = doneCommands_.top();
  			doneCommands_.pop();
  			delete ptr;
  		}
  	}


   void insert(int line, string str) {
      Command *com = new InsertCommand(&doc_, line, str); 
      com->execute(); 
      doneCommands_.push(com); 
   }

   void erase(int line){
      Command *com = new EraseCommand(&doc_, line);
      com->execute();
      doneCommands_.push(com);
   }

   void undo() {
      if(doneCommands_.size() != 0) {
	 Command *com = doneCommands_.top(); 
	 doneCommands_.pop(); 
	 com->unexecute();
	 delete com; // don't forget to delete command
      }else
	 cout << "no commands to undo" << endl; 
   }

   void show(){doc_.show();}
   
   void history(){
		std::stack<Command*> stk;
		int i = 0;
		while(!doneCommands_.empty()){
			++i;
			Command *tmp = doneCommands_.top();
			doneCommands_.pop();
			cout << "Command #" << i << ":\n";
			tmp->show();
			stk.push(tmp);
		}
		while(!stk.empty()){
			Command *tmp = stk.top();
			stk.pop();
			doneCommands_.push(tmp);
		}
	}

	void redo(int n){
		std::stack<Command*> stk;
    Command *tmp;
		for(int i = 0; i < n - 1; ++i){
			tmp = doneCommands_.top();
			doneCommands_.pop();
			stk.push(tmp);
		}
		tmp = doneCommands_.top()->revert();
		tmp->execute();
		for(int i = 0; i < n - 1; ++i){
			doneCommands_.push(stk.top());
			stk.pop();
		}
		doneCommands_.push(tmp);
    cout << "Redo complete\n";
	}
   
   Memento* createMemento() const;
   
   void rollBack(Memento*);

private:
   Document doc_;
   std::stack<Command*> doneCommands_; 
}; 


class Memento {
public:
   Memento(const DocumentWithHistory& doc): doc_(doc) {}
   const DocumentWithHistory& getState() const {return doc_;}  
private:
   DocumentWithHistory doc_;
};

Memento *DocumentWithHistory::createMemento() const{
   // copying the Document itself
   return new Memento(*this);
}

void DocumentWithHistory::rollBack(Memento *mem){
   *this = mem->getState();  // copying back
}


// invoker
int main() {
   DocumentWithHistory his({
	 "Lorem Ipsum is simply dummy text of the printing and typesetting",
	 "industry. Lorem Ipsum has been the industry's standard dummy text",
	 "ever since the 1500s, when an unknown printer took a galley of",
	 "type and scrambled it to make a type specimen book. It has",
	 "survived five centuries."}); 

   char option;
   Memento *mem;

   do{
      his.show(); 
      cout << endl;
      cout << "Enter option (i)nsert line, (e)rase line, (u)ndo last command\n(c)heckpoint, roll(b)ack, (h)istory, (r)edo command, (q)uit: ";
      cin >> option; 
      cout << "\n";

      switch(option){
			case 'i':{
				int line;
				string str;
				cout << "Line number to insert: ";
				cin >> line;
				cout << "Line to insert: ";
				cin.get();
				getline(cin, str);
				his.insert(line, str);
				break;
			}
			case 'e':{
				int line;
				cout << "Line number to remove: ";
				cin >> line;
				his.erase(line);
				break;
			}
			case 'u':{
				his.undo();
				break;
			}
			case 'c':{
				mem = his.createMemento();
				break;
			}
			case 'b':{
				his.rollBack(mem);
				break;
			}
			case 'h':{
				his.history();
				break;
			}
			case 'r':{
				int num;
        cout << "\n";
        his.history();
				cout << "\nEnter number of command to revert: ";
				cin >> num;
				his.redo(num);
				break;
			}
		}
		cout << "_____________________________________________________________________\n\n";
	}while(option != 'q');
	

	return 0;
}