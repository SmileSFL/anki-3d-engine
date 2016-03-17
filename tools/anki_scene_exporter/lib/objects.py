# Copyright (C) 2009-2016, Panagiotis Christopoulos Charitos and contributors.
# All rights reserved.
# Code licensed under the BSD License.
# http://www.anki3d.org/LICENSE
# keep methods in alphabetical order

# blender imports
import bpy

bl_info = {"author": "A. A. Kalugin Jr."}

def get_camera():
	"""
	Gets a camera in the scene.
	If one doesn't exist creates one.
	"""
	def getter():
		obs = bpy.data.objects
		for ob in obs:
			if ob.type == 'CAMERA':
				return ob
	cam = getter()
	if cam == None:
		bpy.ops.object.camera_add()
	return getter()