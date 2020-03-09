#include <dirent.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool starts_with(string s, string start)
{
	return s.rfind(start, 0) == 0;
}

inline bool ends_with(string s, string end)
{ 
	return s.size() >= end.size() && equal(end.rbegin(), end.rend(), s.rbegin());
}

bool file_list_contains_ext(const vector<string>& file_list, string extension)
{
	for (auto file : file_list)
		if (ends_with(file, extension))
			return true;
	return false;
}

static const string problem_start = string("Problem ");
static const string problem_end = string(".cpp");

inline bool is_problem_file(string s)
{
	return starts_with(s, problem_start) && ends_with(s, problem_end);
}

inline string get_problem(string s)
{
	return s.substr(problem_start.size(), s.size() - problem_start.size() - problem_end.size());
}

inline bool file_list_contains_problem(const vector<string>& file_list)
{
	return any_of(file_list.begin(), file_list.end(), is_problem_file);
}

string replace_all(string s, string from, string to)
{
	size_t pos = 0;
	while (pos = s.find(from, pos) != string::npos)
	{
		s.replace(pos, from.size(), to);
		pos += to.size();
	}
	return s;
}

using Folder_File_List = pair<vector<string>, vector<string>>;

inline vector<string>& get_folder_list(Folder_File_List& folder_file_list) { return folder_file_list.first; }
inline vector<string>& get_file_list(Folder_File_List& folder_file_list) { return folder_file_list.second; }

Folder_File_List get_folder_file_list(string path)
{
	Folder_File_List result;
	DIR* dir = opendir(path.c_str());
	if (!dir)
		return result;
	struct dirent *dp;
	readdir(dir); // read "."
	readdir(dir); // read ".."
	while (dp = readdir(dir))
	{
		vector<string>& list = dp->d_type == DT_DIR ? get_folder_list(result) : get_file_list(result);
		list.push_back(string(dp->d_name));
	}
	closedir(dir);
	return result;
}

void create_readme(string current_path, const vector<string>& file_list)
{
	string readme_path = string(current_path + "/" + "README.md");
	ofstream readme_f(readme_path.c_str());
	if (!readme_f)
	{
		cout << "Can't open '" << readme_path << "'" << endl;
		return;
	}
	for (auto file : file_list)
	{
		if (!is_problem_file(file))
			continue;
		readme_f << "## [" << get_problem(file) << "](link_to_paste_here)\n\n<details>\n<summary>Show solution</summary>\n\n```C++\n";
		string problem_path = string(current_path + "/" + file);
		ifstream problem_f(problem_path.c_str());
		if (!problem_f)
		{
			cout << "Can't open '" << problem_path << "'" << endl;
			continue;
		}
		string line;
		while (getline(problem_f, line))
			readme_f << line << "\n";
		readme_f << "```\n</details>\n\n";
		problem_f.close();
	}
	readme_f.close();
	cout << readme_path << " created" << endl;
}

void browse(string current_path, bool bOverwrite)
{
	static const string md_extension = string(".md");

	Folder_File_List folder_file_list = get_folder_file_list(current_path);
	const vector<string>& folder_list = get_folder_list(folder_file_list);
	const vector<string>& file_list = get_file_list(folder_file_list);

	if (file_list_contains_problem(file_list) &&
		(bOverwrite || !file_list_contains_ext(file_list, md_extension)))
	{
		create_readme(current_path, file_list);
	}
	
	for (auto folder : folder_list)
		browse(current_path + "/" + folder, bOverwrite);
}

int main(int argc, char const *argv[])
{
	static const string overwrite_option = string("-f");

	bool bOverwrite = (argc > 1) && (string(argv[1]) == overwrite_option);
	browse(string("."), bOverwrite);

	return 0;
}
