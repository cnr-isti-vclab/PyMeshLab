#include <iostream>

#include "pymeshlab/helpers/common.h"
#include "pymeshlab/module_functions.h"

#include <QFile>

bool writeFile(const std::string& file_content, const QString fileName)
{
	QString baseDir(PYMESHLAB_STRINGIFY(PYMESHLAB_SRC_BASE_DIR));

	QFile f(baseDir + "/../../docs/" + fileName);//filter_list.rst");

	if (!f.open(QIODevice::WriteOnly)) {
		std::cerr << "Could not open docs/" + fileName.toStdString() + " file.\n";
		return false;
	}

	f.write(file_content.data());

	f.close();
	return true;
}

int main(int , char *[])
{
	pymeshlab::loadDefaultPlugins();
	std::string doc_filters = pymeshlab::filterListRSTDocumentation();
	bool b = writeFile(doc_filters, "filter_list.rst");
	if (!b)
		return -1;

	std::string doc_io = pymeshlab::ioFormatListRSTDocumentation();
	b = writeFile(doc_io, "io_format_list.rst");
	if (!b)
		return -1;

	return 0;
}
