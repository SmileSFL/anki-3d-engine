// Copyright (C) 2009-2018, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include <anki/resource/Script.h>
#include <anki/util/File.h>

namespace anki
{

Script::~Script()
{
	m_source.destroy(getAllocator());
}

Error Script::load(const ResourceFilename& filename, Bool async)
{
	ResourceFilePtr file;
	ANKI_CHECK(openFile(filename, file));

	ANKI_CHECK(file->readAllText(getAllocator(), m_source));

	return Error::NONE;
}

} // end namespace anki
