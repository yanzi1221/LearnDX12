#include "GeometryGenerator.hpp"
#include <algorithm>

GeometryGenerator::MeshData GeometryGenerator::createBox(float width, float height, float depth, uint32_t numSubdivisions)

											
{
    MeshData data;

    Vertex v[24];

    	float w2 = 0.5f*width;
	float h2 = 0.5f*height;
	float d2 = 0.5f*depth;
    
	// Fill in the front face vertex data.
	v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the back face vertex data.
	v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the top face vertex data.
	v[8]  = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[9]  = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the bottom face vertex data.
	v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the left face vertex data.
	v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	// Fill in the right face vertex data.
	v[20] = Vertex(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[21] = Vertex(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[22] = Vertex(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	v[23] = Vertex(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	data._vertices.assign(&v[0], &v[24]);
 
	//
	// Create the indices.
	//

	uint32_t i[36];

	// Fill in the front face index data
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	// Fill in the back face index data
	i[6] = 4; i[7]  = 5; i[8]  = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	// Fill in the top face index data
	i[12] = 8; i[13] =  9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	// Fill in the bottom face index data
	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	// Fill in the left face index data
	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	// Fill in the right face index data
	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;

	data._indices32.assign(&i[0], &i[36]);

    // Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32_t>(numSubdivisions, 6u);

    for(uint32_t i = 0; i < numSubdivisions; ++i)
        subdivide(data);

    return data;
}

GeometryGenerator::MeshData GeometryGenerator::createSphere(float radius, uint32_t sliceCount, uint32_t stackCount)
{
   MeshData meshData;

	//
	// Compute the _vertices stating at the top pole and moving down the stacks.
	//

	// Poles: note that there will be texture coordinate distortion as there is
	// not a unique point on the texture map to assign to the pole when mapping
	// a rectangular texture onto a sphere.
	Vertex topVertex(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Vertex bottomVertex(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData._vertices.push_back( topVertex );

	float phiStep   = XM_PI / stackCount;
	float thetaStep = 2.0f * XM_PI / sliceCount;

	// Compute _vertices for each stack ring (do not count the poles as rings).
	for(uint32_t i = 1; i <= stackCount-1; ++i)
	{
		float phi = i * phiStep;

		// _vertices of ring.
        for(auto j = 0; j <= sliceCount; ++j)
		{
			float theta = j*thetaStep;

			Vertex v;

			// spherical to cartesian
			v._position.x = radius * sinf(phi) * cosf(theta);
			v._position.y = radius * cosf(phi);
			v._position.z = radius * sinf(phi) * sinf(theta);

			// Partial derivative of P with respect to theta
			v._tangentU.x = -radius * sinf(phi) * sinf(theta);
			v._tangentU.y = 0.0f;
			v._tangentU.z = +radius * sinf(phi) * cosf(theta);

			XMVECTOR T = XMLoadFloat3(&v._tangentU);
			XMStoreFloat3(&v._tangentU, XMVector3Normalize(T));

			XMVECTOR p = XMLoadFloat3(&v._position);
			XMStoreFloat3(&v._normal, XMVector3Normalize(p));

			v._texCoord.x = theta / XM_2PI;
			v._texCoord.y = phi / XM_PI;

			meshData._vertices.push_back( v );
		}
	}

	meshData._vertices.push_back( bottomVertex );

	//
	// Compute indices for top stack.  The top stack was written first to the vertex buffer
	// and connects the top pole to the first ring.
	//

    for(auto i = 1; i <= sliceCount; ++i)
	{
		meshData._indices32.push_back(0);
		meshData._indices32.push_back(i+1);
		meshData._indices32.push_back(i);
	}
	
	//
	// Compute indices for inner stacks (not connected to poles).
	//

	// Offset the indices to the index of the first vertex in the first ring.
	// This is just skipping the top pole vertex.
    uint32_t baseIndex = 1;
    uint32_t ringVertexCount = sliceCount + 1;
	for(auto i = 0; i < stackCount-2; ++i)
	{
		for(auto j = 0; j < sliceCount; ++j)
		{
			meshData._indices32.push_back(baseIndex + i * ringVertexCount + j);
			meshData._indices32.push_back(baseIndex + i * ringVertexCount + j + 1);
			meshData._indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j);

			meshData._indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j);
			meshData._indices32.push_back(baseIndex + i * ringVertexCount + j + 1);
			meshData._indices32.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
		}
	}

	//
	// Compute indices for bottom stack.  The bottom stack was written last to the vertex buffer
	// and connects the bottom pole to the bottom ring.
	//

	// South pole vertex was added last.
	auto southPoleIndex = (uint32_t)meshData._vertices.size() - 1;

	// Offset the indices to the index of the first vertex in the last ring.
	baseIndex = southPoleIndex - ringVertexCount;
	
	for(auto i = 0; i < sliceCount; ++i)
	{
		meshData._indices32.push_back(southPoleIndex);
		meshData._indices32.push_back(baseIndex + i);
		meshData._indices32.push_back(baseIndex + i + 1);
	}

    return meshData;
}

void GeometryGenerator::subdivide(MeshData& meshData)
{
	// Save a copy of the input geometry.
	MeshData inputCopy = meshData;


	meshData._vertices.resize(0);
	meshData._indices32.resize(0);

	//       v1
	//       *
	//      / \
	//     /   \
	//  m0*-----*m1
	//   / \   / \
	//  /   \ /   \
	// *-----*-----*
	// v0    m2     v2

	auto numTris = (uint32_t)inputCopy._indices32.size() / 3;
	for(auto i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy._vertices[ inputCopy._indices32[i*3+0] ];
		Vertex v1 = inputCopy._vertices[ inputCopy._indices32[i*3+1] ];
		Vertex v2 = inputCopy._vertices[ inputCopy._indices32[i*3+2] ];

		//
		// Generate the midpoints.
		//

        Vertex m0 = midPoint(v0, v1);
        Vertex m1 = midPoint(v1, v2);
        Vertex m2 = midPoint(v0, v2);

		//
		// Add new geometry.
		//

		meshData._vertices.push_back(v0); // 0
		meshData._vertices.push_back(v1); // 1
		meshData._vertices.push_back(v2); // 2
		meshData._vertices.push_back(m0); // 3
		meshData._vertices.push_back(m1); // 4
		meshData._vertices.push_back(m2); // 5
 
		meshData._indices32.push_back(i * 6 + 0);
		meshData._indices32.push_back(i * 6 + 3);
		meshData._indices32.push_back(i * 6 + 5);

		meshData._indices32.push_back(i * 6 + 3);
		meshData._indices32.push_back(i * 6 + 4);
		meshData._indices32.push_back(i * 6 + 5);

		meshData._indices32.push_back(i * 6 + 5);
		meshData._indices32.push_back(i * 6 + 4);
		meshData._indices32.push_back(i * 6 + 2);

		meshData._indices32.push_back(i * 6 + 3);
		meshData._indices32.push_back(i * 6 + 1);
		meshData._indices32.push_back(i * 6 + 4);
	}
}

GeometryGenerator::Vertex GeometryGenerator::midPoint(const Vertex& v0, const Vertex& v1)
{
    XMVECTOR p0 = XMLoadFloat3(&v0._position);
    XMVECTOR p1 = XMLoadFloat3(&v1._position);

    XMVECTOR n0 = XMLoadFloat3(&v0._normal);
    XMVECTOR n1 = XMLoadFloat3(&v1._normal);

    XMVECTOR tan0 = XMLoadFloat3(&v0._tangentU);
    XMVECTOR tan1 = XMLoadFloat3(&v1._tangentU);

    XMVECTOR tex0 = XMLoadFloat2(&v0._texCoord);
    XMVECTOR tex1 = XMLoadFloat2(&v1._texCoord);

    // Compute the midpoints of all the attributes.  Vectors need to be normalized
    // since linear interpolating can make them not unit length.  
    XMVECTOR pos = 0.5f * (p0 + p1);
    XMVECTOR normal = XMVector3Normalize(0.5f * (n0 + n1));
    XMVECTOR tangent = XMVector3Normalize(0.5f * (tan0 + tan1));
    XMVECTOR tex = 0.5f * (tex0 + tex1);

    Vertex v;
    XMStoreFloat3(&v._position, pos);
    XMStoreFloat3(&v._normal, normal);
    XMStoreFloat3(&v._tangentU, tangent);
    XMStoreFloat2(&v._texCoord, tex);

    return v;
}

GeometryGenerator::MeshData GeometryGenerator::createGeosphere(float radius, uint32_t numSubdivisions)
{
    MeshData meshData;

	// Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32_t>(numSubdivisions, 6u);

	// Approximate a sphere by tessellating an icosahedron.

	const float X = 0.525731f; 
	const float Z = 0.850651f;

	XMFLOAT3 pos[12] = 
	{
		XMFLOAT3(-X, 0.0f, Z),  XMFLOAT3(X, 0.0f, Z),  
		XMFLOAT3(-X, 0.0f, -Z), XMFLOAT3(X, 0.0f, -Z),    
		XMFLOAT3(0.0f, Z, X),   XMFLOAT3(0.0f, Z, -X), 
		XMFLOAT3(0.0f, -Z, X),  XMFLOAT3(0.0f, -Z, -X),    
		XMFLOAT3(Z, X, 0.0f),   XMFLOAT3(-Z, X, 0.0f), 
		XMFLOAT3(Z, -X, 0.0f),  XMFLOAT3(-Z, -X, 0.0f)
	};

    uint32_t k[60] =
	{
		1,4,0,  4,9,0,  4,5,9,  8,5,4,  1,8,4,    
		1,10,8, 10,3,8, 8,3,5,  3,2,5,  3,7,2,    
		3,10,7, 10,6,7, 6,11,7, 6,0,11, 6,1,0, 
		10,1,6, 11,0,9, 2,11,9, 5,2,9,  11,2,7 
	};

    meshData._vertices.resize(12);
    meshData._indices32.assign(&k[0], &k[60]);

	for(auto i = 0; i < 12; ++i)
		meshData._vertices[i]._position = pos[i];

	for(auto i = 0; i < numSubdivisions; ++i)
		subdivide(meshData);

	// Project _vertices onto sphere and scale.
	for(auto i = 0; i < meshData._vertices.size(); ++i)
	{
		// Project onto unit sphere.
		XMVECTOR n = XMVector3Normalize(XMLoadFloat3(&meshData._vertices[i]._position));

		// Project onto sphere.
		XMVECTOR p = radius*n;

		XMStoreFloat3(&meshData._vertices[i]._position, p);
		XMStoreFloat3(&meshData._vertices[i]._normal, n);

		// Derive texture coordinates from spherical coordinates.
        float theta = atan2f(meshData._vertices[i]._position.z, meshData._vertices[i]._position.x);

        // Put in [0, 2pi].
        if(theta < 0.0f)
            theta += XM_2PI;

		float phi = acosf(meshData._vertices[i]._position.y / radius);

		meshData._vertices[i]._texCoord.x = theta/XM_2PI;
		meshData._vertices[i]._texCoord.y = phi/XM_PI;

		// Partial derivative of P with respect to theta
		meshData._vertices[i]._tangentU.x = -radius*sinf(phi)*sinf(theta);
		meshData._vertices[i]._tangentU.y = 0.0f;
		meshData._vertices[i]._tangentU.z = +radius*sinf(phi)*cosf(theta);

		XMVECTOR T = XMLoadFloat3(&meshData._vertices[i]._tangentU);
		XMStoreFloat3(&meshData._vertices[i]._tangentU, XMVector3Normalize(T));
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::createCylinder(float bottomRadius, float topRadius, 
                                                    float height, uint32_t sliceCount, uint32_t stackCount)
{
    MeshData meshData;

	//
	// Build Stacks.
	// 

	float stackHeight = height / stackCount;

	// Amount to increment radius as we move up each stack level from bottom to top.
	float radiusStep = (topRadius - bottomRadius) / stackCount;

	uint32_t ringCount = stackCount+1;

	// Compute _vertices for each stack ring starting at the bottom and moving up.
	for(uint32_t i = 0; i < ringCount; ++i)
	{
		float y = -0.5f * height + i * stackHeight;
		float r = bottomRadius + i * radiusStep;

		// _vertices of ring
		float dTheta = 2.0f * XM_PI/sliceCount;
		for(uint32_t j = 0; j <= sliceCount; ++j)
		{
			Vertex vertex;

			float c = cosf(j * dTheta);
			float s = sinf(j * dTheta);

			vertex._position = XMFLOAT3(r*c, y, r*s);

			vertex._texCoord.x = (float)(j / sliceCount);
			vertex._texCoord.y = 1.0f - (float)(i / stackCount);

			// Cylinder can be parameterized as follows, where we introduce v
			// parameter that goes in the same direction as the v tex-coord
			// so that the bitangent goes in the same direction as the v tex-coord.
			//   Let r0 be the bottom radius and let r1 be the top radius.
			//   y(v) = h - hv for v in [0,1].
			//   r(v) = r1 + (r0-r1)v
			//
			//   x(t, v) = r(v)*cos(t)
			//   y(t, v) = h - hv
			//   z(t, v) = r(v)*sin(t)
			// 
			//  dx/dt = -r(v)*sin(t)
			//  dy/dt = 0
			//  dz/dt = +r(v)*cos(t)
			//
			//  dx/dv = (r0-r1)*cos(t)
			//  dy/dv = -h
			//  dz/dv = (r0-r1)*sin(t)

			// This is unit length.
			vertex._tangentU = XMFLOAT3(-s, 0.0f, c);

			float dr = bottomRadius-topRadius;
			XMFLOAT3 bitangent(dr*c, -height, dr * s);

			XMVECTOR T = XMLoadFloat3(&vertex._tangentU);
			XMVECTOR B = XMLoadFloat3(&bitangent);
			XMVECTOR N = XMVector3Normalize(XMVector3Cross(T, B));
			XMStoreFloat3(&vertex._normal, N);

			meshData._vertices.push_back(vertex);
		}
	}

	// Add one because we duplicate the first and last vertex per ring
	// since the texture coordinates are different.
	uint32_t ringVertexCount = sliceCount+1;

	// Compute indices for each stack.
	for(auto i = 0; i < stackCount; ++i)
	{
		for(auto j = 0; j < sliceCount; ++j)
		{
			meshData._indices32.push_back(i * ringVertexCount + j);
			meshData._indices32.push_back((i + 1) * ringVertexCount + j);
			meshData._indices32.push_back((i + 1) * ringVertexCount + j + 1);

			meshData._indices32.push_back(i * ringVertexCount + j);
			meshData._indices32.push_back((i + 1) * ringVertexCount + j + 1);
			meshData._indices32.push_back(i * ringVertexCount + j + 1);
		}
	}

	createCylinderTopCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);
	createCylinderBottomCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);

    return meshData;
}

void GeometryGenerator::createCylinderTopCap(float bottomRadius, float topRadius, float height,
											uint32_t sliceCount, uint32_t stackCount, MeshData& meshData)
{
	uint32_t baseIndex = (uint32_t)meshData._vertices.size();

	float y = 0.5f*height;
	float dTheta = 2.0f*XM_PI/sliceCount;

	// Duplicate cap ring _vertices because the texture coordinates and normals differ.
	for(auto i = 0; i <= sliceCount; ++i)
	{
		float x = topRadius*cosf(i*dTheta);
		float z = topRadius*sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData._vertices.push_back( Vertex(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData._vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Index of center vertex.
	auto centerIndex = (uint32_t)meshData._vertices.size() - 1;

	for(uint32_t i = 0; i < sliceCount; ++i)
	{
		meshData._indices32.push_back(centerIndex);
		meshData._indices32.push_back(baseIndex + i+1);
		meshData._indices32.push_back(baseIndex + i);
	}
}

void GeometryGenerator::createCylinderBottomCap(float bottomRadius, float topRadius, float height,
											   uint32_t sliceCount, uint32_t stackCount, MeshData& meshData)
{
	// 
	// Build bottom cap.
	//

	auto baseIndex = (uint32_t)meshData._vertices.size();
	float y = -0.5f * height;

	// _vertices of ring
	float dTheta = 2.0f*XM_PI/sliceCount;
	for(uint32_t i = 0; i <= sliceCount; ++i)
	{
		float x = bottomRadius * cosf(i * dTheta);
		float z = bottomRadius * sinf(i * dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData._vertices.push_back( Vertex(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData._vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Cache the index of center vertex.
	auto centerIndex = (uint32_t)meshData._vertices.size()-1;

	for(auto i = 0; i < sliceCount; ++i)
	{
		meshData._indices32.push_back(centerIndex);
		meshData._indices32.push_back(baseIndex + i);
		meshData._indices32.push_back(baseIndex + i + 1);
	}
}

GeometryGenerator::MeshData GeometryGenerator::createGrid(float width, float depth, uint32_t m, uint32_t n)
{
    MeshData meshData;

	auto vertexCount = m * n;
	auto faceCount = (m - 1) * (n-1) * 2;

	//
	// Create the _vertices.
	//

	float halfWidth = 0.5f*width;
	float halfDepth = 0.5f*depth;

	float dx = width / (n-1);
	float dz = depth / (m-1);

	float du = 1.0f / (n-1);
	float dv = 1.0f / (m-1);

	meshData._vertices.resize(vertexCount);
	for(auto i = 0; i < m; ++i)
	{
		float z = halfDepth - i*dz;
		for(auto j = 0; j < n; ++j)
		{
			float x = -halfWidth + j*dx;

			meshData._vertices[i * n + j]._position = XMFLOAT3(x, 0.0f, z);
			meshData._vertices[i * n + j]._normal   = XMFLOAT3(0.0f, 1.0f, 0.0f);
			meshData._vertices[i * n + j]._tangentU = XMFLOAT3(1.0f, 0.0f, 0.0f);

			// Stretch texture over grid.
			meshData._vertices[i * n + j]._texCoord.x = j * du;
			meshData._vertices[i * n + j ]._texCoord.y = i * dv;
		}
	}
 
    //
	// Create the indices.
	//

	meshData._indices32.resize(faceCount*3); // 3 indices per face

	// Iterate over each quad and compute indices.
	uint32_t k = 0;
	for(auto i = 0; i < m-1; ++i)
	{
		for(auto j = 0; j < n-1; ++j)
		{
			meshData._indices32[k]   = i * n + j;
			meshData._indices32[k + 1] = i * n + j + 1;
			meshData._indices32[k + 2] = (i + 1) * n + j;

			meshData._indices32[k + 3] = (i + 1) * n + j;
			meshData._indices32[k + 4] = i * n + j + 1;
			meshData._indices32[k + 5] = (i + 1) * n + j + 1;

			k += 6; // next quad
		}
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::createQuad(float x, float y, float w, float h, float depth)
{
    MeshData meshData;

	meshData._vertices.resize(4);
	meshData._indices32.resize(6);

	// Position coordinates specified in NDC space.
	meshData._vertices[0] = Vertex(
        x, y - h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f);

	meshData._vertices[1] = Vertex(
		x, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f);

	meshData._vertices[2] = Vertex(
		x+w, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f);

	meshData._vertices[3] = Vertex(
		x+w, y-h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f);

	meshData._indices32[0] = 0;
	meshData._indices32[1] = 1;
	meshData._indices32[2] = 2;

	meshData._indices32[3] = 0;
	meshData._indices32[4] = 2;
	meshData._indices32[5] = 3;

    return meshData;
}


//***************************************************************************************
// GeometryGenerator.cpp by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************

// #include "GeometryGenerator.hpp"
// #include <algorithm>

// using namespace DirectX;

// GeometryGenerator::MeshData GeometryGenerator::createBox(float width, float height, float depth, uint32 numSubdivisions)
// {
//     MeshData meshData;

//     //
// 	// Create the _vertices.
// 	//

// 	Vertex v[24];

// 	float w2 = 0.5f*width;
// 	float h2 = 0.5f*height;
// 	float d2 = 0.5f*depth;
    
// 	// Fill in the front face vertex data.
// 	v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
// 	v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
// 	v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
// 	v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

// 	// Fill in the back face vertex data.
// 	v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
// 	v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
// 	v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
// 	v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

// 	// Fill in the top face vertex data.
// 	v[8]  = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
// 	v[9]  = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
// 	v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
// 	v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

// 	// Fill in the bottom face vertex data.
// 	v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
// 	v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
// 	v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
// 	v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

// 	// Fill in the left face vertex data.
// 	v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
// 	v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
// 	v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
// 	v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

// 	// Fill in the right face vertex data.
// 	v[20] = Vertex(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
// 	v[21] = Vertex(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
// 	v[22] = Vertex(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
// 	v[23] = Vertex(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

// 	meshData._vertices.assign(&v[0], &v[24]);
 
// 	//
// 	// Create the indices.
// 	//

// 	uint32 i[36];

// 	// Fill in the front face index data
// 	i[0] = 0; i[1] = 1; i[2] = 2;
// 	i[3] = 0; i[4] = 2; i[5] = 3;

// 	// Fill in the back face index data
// 	i[6] = 4; i[7]  = 5; i[8]  = 6;
// 	i[9] = 4; i[10] = 6; i[11] = 7;

// 	// Fill in the top face index data
// 	i[12] = 8; i[13] =  9; i[14] = 10;
// 	i[15] = 8; i[16] = 10; i[17] = 11;

// 	// Fill in the bottom face index data
// 	i[18] = 12; i[19] = 13; i[20] = 14;
// 	i[21] = 12; i[22] = 14; i[23] = 15;

// 	// Fill in the left face index data
// 	i[24] = 16; i[25] = 17; i[26] = 18;
// 	i[27] = 16; i[28] = 18; i[29] = 19;

// 	// Fill in the right face index data
// 	i[30] = 20; i[31] = 21; i[32] = 22;
// 	i[33] = 20; i[34] = 22; i[35] = 23;

// 	meshData._indices32.assign(&i[0], &i[36]);

//     // Put a cap on the number of subdivisions.
//     numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

//     for(uint32 i = 0; i < numSubdivisions; ++i)
//         subdivide(meshData);

//     return meshData;
// }

// GeometryGenerator::MeshData GeometryGenerator::createSphere(float radius, uint32 sliceCount, uint32 stackCount)
// {
//     MeshData meshData;

// 	//
// 	// Compute the _vertices stating at the top pole and moving down the stacks.
// 	//

// 	// Poles: note that there will be texture coordinate distortion as there is
// 	// not a unique point on the texture map to assign to the pole when mapping
// 	// a rectangular texture onto a sphere.
// 	Vertex topVertex(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
// 	Vertex bottomVertex(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

// 	meshData._vertices.push_back( topVertex );

// 	float phiStep   = XM_PI/stackCount;
// 	float thetaStep = 2.0f*XM_PI/sliceCount;

// 	// Compute _vertices for each stack ring (do not count the poles as rings).
// 	for(uint32 i = 1; i <= stackCount-1; ++i)
// 	{
// 		float phi = i*phiStep;

// 		// _vertices of ring.
//         for(uint32 j = 0; j <= sliceCount; ++j)
// 		{
// 			float theta = j*thetaStep;

// 			Vertex v;

// 			// spherical to cartesian
// 			v.Position.x = radius*sinf(phi)*cosf(theta);
// 			v.Position.y = radius*cosf(phi);
// 			v.Position.z = radius*sinf(phi)*sinf(theta);

// 			// Partial derivative of P with respect to theta
// 			v.TangentU.x = -radius*sinf(phi)*sinf(theta);
// 			v.TangentU.y = 0.0f;
// 			v.TangentU.z = +radius*sinf(phi)*cosf(theta);

// 			XMVECTOR T = XMLoadFloat3(&v.TangentU);
// 			XMStoreFloat3(&v.TangentU, XMVector3Normalize(T));

// 			XMVECTOR p = XMLoadFloat3(&v.Position);
// 			XMStoreFloat3(&v.Normal, XMVector3Normalize(p));

// 			v.TexC.x = theta / XM_2PI;
// 			v.TexC.y = phi / XM_PI;

// 			meshData._vertices.push_back( v );
// 		}
// 	}

// 	meshData._vertices.push_back( bottomVertex );

// 	//
// 	// Compute indices for top stack.  The top stack was written first to the vertex buffer
// 	// and connects the top pole to the first ring.
// 	//

//     for(uint32 i = 1; i <= sliceCount; ++i)
// 	{
// 		meshData._indices32.push_back(0);
// 		meshData._indices32.push_back(i+1);
// 		meshData._indices32.push_back(i);
// 	}
	
// 	//
// 	// Compute indices for inner stacks (not connected to poles).
// 	//

// 	// Offset the indices to the index of the first vertex in the first ring.
// 	// This is just skipping the top pole vertex.
//     uint32 baseIndex = 1;
//     uint32 ringVertexCount = sliceCount + 1;
// 	for(uint32 i = 0; i < stackCount-2; ++i)
// 	{
// 		for(uint32 j = 0; j < sliceCount; ++j)
// 		{
// 			meshData._indices32.push_back(baseIndex + i*ringVertexCount + j);
// 			meshData._indices32.push_back(baseIndex + i*ringVertexCount + j+1);
// 			meshData._indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);

// 			meshData._indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);
// 			meshData._indices32.push_back(baseIndex + i*ringVertexCount + j+1);
// 			meshData._indices32.push_back(baseIndex + (i+1)*ringVertexCount + j+1);
// 		}
// 	}

// 	//
// 	// Compute indices for bottom stack.  The bottom stack was written last to the vertex buffer
// 	// and connects the bottom pole to the bottom ring.
// 	//

// 	// South pole vertex was added last.
// 	uint32 southPoleIndex = (uint32)meshData._vertices.size()-1;

// 	// Offset the indices to the index of the first vertex in the last ring.
// 	baseIndex = southPoleIndex - ringVertexCount;
	
// 	for(uint32 i = 0; i < sliceCount; ++i)
// 	{
// 		meshData._indices32.push_back(southPoleIndex);
// 		meshData._indices32.push_back(baseIndex+i);
// 		meshData._indices32.push_back(baseIndex+i+1);
// 	}

//     return meshData;
// }
 
// void GeometryGenerator::subdivide(MeshData& meshData)
// {
// 	// Save a copy of the input geometry.
// 	MeshData inputCopy = meshData;


// 	meshData._vertices.resize(0);
// 	meshData._indices32.resize(0);

// 	//       v1
// 	//       *
// 	//      / \
// 	//     /   \
// 	//  m0*-----*m1
// 	//   / \   / \
// 	//  /   \ /   \
// 	// *-----*-----*
// 	// v0    m2     v2

// 	uint32 numTris = (uint32)inputCopy._indices32.size()/3;
// 	for(uint32 i = 0; i < numTris; ++i)
// 	{
// 		Vertex v0 = inputCopy._vertices[ inputCopy._indices32[i*3+0] ];
// 		Vertex v1 = inputCopy._vertices[ inputCopy._indices32[i*3+1] ];
// 		Vertex v2 = inputCopy._vertices[ inputCopy._indices32[i*3+2] ];

// 		//
// 		// Generate the midpoints.
// 		//

//         Vertex m0 = midPoint(v0, v1);
//         Vertex m1 = midPoint(v1, v2);
//         Vertex m2 = midPoint(v0, v2);

// 		//
// 		// Add new geometry.
// 		//

// 		meshData._vertices.push_back(v0); // 0
// 		meshData._vertices.push_back(v1); // 1
// 		meshData._vertices.push_back(v2); // 2
// 		meshData._vertices.push_back(m0); // 3
// 		meshData._vertices.push_back(m1); // 4
// 		meshData._vertices.push_back(m2); // 5
 
// 		meshData._indices32.push_back(i*6+0);
// 		meshData._indices32.push_back(i*6+3);
// 		meshData._indices32.push_back(i*6+5);

// 		meshData._indices32.push_back(i*6+3);
// 		meshData._indices32.push_back(i*6+4);
// 		meshData._indices32.push_back(i*6+5);

// 		meshData._indices32.push_back(i*6+5);
// 		meshData._indices32.push_back(i*6+4);
// 		meshData._indices32.push_back(i*6+2);

// 		meshData._indices32.push_back(i*6+3);
// 		meshData._indices32.push_back(i*6+1);
// 		meshData._indices32.push_back(i*6+4);
// 	}
// }

// GeometryGenerator::Vertex GeometryGenerator::midPoint(const Vertex& v0, const Vertex& v1)
// {
//     XMVECTOR p0 = XMLoadFloat3(&v0.Position);
//     XMVECTOR p1 = XMLoadFloat3(&v1.Position);

//     XMVECTOR n0 = XMLoadFloat3(&v0.Normal);
//     XMVECTOR n1 = XMLoadFloat3(&v1.Normal);

//     XMVECTOR tan0 = XMLoadFloat3(&v0.TangentU);
//     XMVECTOR tan1 = XMLoadFloat3(&v1.TangentU);

//     XMVECTOR tex0 = XMLoadFloat2(&v0.TexC);
//     XMVECTOR tex1 = XMLoadFloat2(&v1.TexC);

//     // Compute the midpoints of all the attributes.  Vectors need to be normalized
//     // since linear interpolating can make them not unit length.  
//     XMVECTOR pos = 0.5f*(p0 + p1);
//     XMVECTOR normal = XMVector3Normalize(0.5f*(n0 + n1));
//     XMVECTOR tangent = XMVector3Normalize(0.5f*(tan0+tan1));
//     XMVECTOR tex = 0.5f*(tex0 + tex1);

//     Vertex v;
//     XMStoreFloat3(&v.Position, pos);
//     XMStoreFloat3(&v.Normal, normal);
//     XMStoreFloat3(&v.TangentU, tangent);
//     XMStoreFloat2(&v.TexC, tex);

//     return v;
// }

// GeometryGenerator::MeshData GeometryGenerator::createGeosphere(float radius, uint32 numSubdivisions)
// {
//     MeshData meshData;

// 	// Put a cap on the number of subdivisions.
//     numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

// 	// Approximate a sphere by tessellating an icosahedron.

// 	const float X = 0.525731f; 
// 	const float Z = 0.850651f;

// 	XMFLOAT3 pos[12] = 
// 	{
// 		XMFLOAT3(-X, 0.0f, Z),  XMFLOAT3(X, 0.0f, Z),  
// 		XMFLOAT3(-X, 0.0f, -Z), XMFLOAT3(X, 0.0f, -Z),    
// 		XMFLOAT3(0.0f, Z, X),   XMFLOAT3(0.0f, Z, -X), 
// 		XMFLOAT3(0.0f, -Z, X),  XMFLOAT3(0.0f, -Z, -X),    
// 		XMFLOAT3(Z, X, 0.0f),   XMFLOAT3(-Z, X, 0.0f), 
// 		XMFLOAT3(Z, -X, 0.0f),  XMFLOAT3(-Z, -X, 0.0f)
// 	};

//     uint32 k[60] =
// 	{
// 		1,4,0,  4,9,0,  4,5,9,  8,5,4,  1,8,4,    
// 		1,10,8, 10,3,8, 8,3,5,  3,2,5,  3,7,2,    
// 		3,10,7, 10,6,7, 6,11,7, 6,0,11, 6,1,0, 
// 		10,1,6, 11,0,9, 2,11,9, 5,2,9,  11,2,7 
// 	};

//     meshData._vertices.resize(12);
//     meshData._indices32.assign(&k[0], &k[60]);

// 	for(uint32 i = 0; i < 12; ++i)
// 		meshData._vertices[i].Position = pos[i];

// 	for(uint32 i = 0; i < numSubdivisions; ++i)
// 		subdivide(meshData);

// 	// Project _vertices onto sphere and scale.
// 	for(uint32 i = 0; i < meshData._vertices.size(); ++i)
// 	{
// 		// Project onto unit sphere.
// 		XMVECTOR n = XMVector3Normalize(XMLoadFloat3(&meshData._vertices[i].Position));

// 		// Project onto sphere.
// 		XMVECTOR p = radius*n;

// 		XMStoreFloat3(&meshData._vertices[i].Position, p);
// 		XMStoreFloat3(&meshData._vertices[i].Normal, n);

// 		// Derive texture coordinates from spherical coordinates.
//         float theta = atan2f(meshData._vertices[i].Position.z, meshData._vertices[i].Position.x);

//         // Put in [0, 2pi].
//         if(theta < 0.0f)
//             theta += XM_2PI;

// 		float phi = acosf(meshData._vertices[i].Position.y / radius);

// 		meshData._vertices[i].TexC.x = theta/XM_2PI;
// 		meshData._vertices[i].TexC.y = phi/XM_PI;

// 		// Partial derivative of P with respect to theta
// 		meshData._vertices[i].TangentU.x = -radius*sinf(phi)*sinf(theta);
// 		meshData._vertices[i].TangentU.y = 0.0f;
// 		meshData._vertices[i].TangentU.z = +radius*sinf(phi)*cosf(theta);

// 		XMVECTOR T = XMLoadFloat3(&meshData._vertices[i].TangentU);
// 		XMStoreFloat3(&meshData._vertices[i].TangentU, XMVector3Normalize(T));
// 	}

//     return meshData;
// }

// GeometryGenerator::MeshData GeometryGenerator::createCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
// {
//     MeshData meshData;

// 	//
// 	// Build Stacks.
// 	// 

// 	float stackHeight = height / stackCount;

// 	// Amount to increment radius as we move up each stack level from bottom to top.
// 	float radiusStep = (topRadius - bottomRadius) / stackCount;

// 	uint32 ringCount = stackCount+1;

// 	// Compute _vertices for each stack ring starting at the bottom and moving up.
// 	for(uint32 i = 0; i < ringCount; ++i)
// 	{
// 		float y = -0.5f*height + i*stackHeight;
// 		float r = bottomRadius + i*radiusStep;

// 		// _vertices of ring
// 		float dTheta = 2.0f*XM_PI/sliceCount;
// 		for(uint32 j = 0; j <= sliceCount; ++j)
// 		{
// 			Vertex vertex;

// 			float c = cosf(j*dTheta);
// 			float s = sinf(j*dTheta);

// 			vertex.Position = XMFLOAT3(r*c, y, r*s);

// 			vertex.TexC.x = (float)j/sliceCount;
// 			vertex.TexC.y = 1.0f - (float)i/stackCount;

// 			// Cylinder can be parameterized as follows, where we introduce v
// 			// parameter that goes in the same direction as the v tex-coord
// 			// so that the bitangent goes in the same direction as the v tex-coord.
// 			//   Let r0 be the bottom radius and let r1 be the top radius.
// 			//   y(v) = h - hv for v in [0,1].
// 			//   r(v) = r1 + (r0-r1)v
// 			//
// 			//   x(t, v) = r(v)*cos(t)
// 			//   y(t, v) = h - hv
// 			//   z(t, v) = r(v)*sin(t)
// 			// 
// 			//  dx/dt = -r(v)*sin(t)
// 			//  dy/dt = 0
// 			//  dz/dt = +r(v)*cos(t)
// 			//
// 			//  dx/dv = (r0-r1)*cos(t)
// 			//  dy/dv = -h
// 			//  dz/dv = (r0-r1)*sin(t)

// 			// This is unit length.
// 			vertex.TangentU = XMFLOAT3(-s, 0.0f, c);

// 			float dr = bottomRadius-topRadius;
// 			XMFLOAT3 bitangent(dr*c, -height, dr*s);

// 			XMVECTOR T = XMLoadFloat3(&vertex.TangentU);
// 			XMVECTOR B = XMLoadFloat3(&bitangent);
// 			XMVECTOR N = XMVector3Normalize(XMVector3Cross(T, B));
// 			XMStoreFloat3(&vertex.Normal, N);

// 			meshData._vertices.push_back(vertex);
// 		}
// 	}

// 	// Add one because we duplicate the first and last vertex per ring
// 	// since the texture coordinates are different.
// 	uint32 ringVertexCount = sliceCount+1;

// 	// Compute indices for each stack.
// 	for(uint32 i = 0; i < stackCount; ++i)
// 	{
// 		for(uint32 j = 0; j < sliceCount; ++j)
// 		{
// 			meshData._indices32.push_back(i*ringVertexCount + j);
// 			meshData._indices32.push_back((i+1)*ringVertexCount + j);
// 			meshData._indices32.push_back((i+1)*ringVertexCount + j+1);

// 			meshData._indices32.push_back(i*ringVertexCount + j);
// 			meshData._indices32.push_back((i+1)*ringVertexCount + j+1);
// 			meshData._indices32.push_back(i*ringVertexCount + j+1);
// 		}
// 	}

// 	buildCylinderTopCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);
// 	buildCylinderBottomCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);

//     return meshData;
// }

// void GeometryGenerator::buildCylinderTopCap(float bottomRadius, float topRadius, float height,
// 											uint32 sliceCount, uint32 stackCount, MeshData& meshData)
// {
// 	uint32 baseIndex = (uint32)meshData._vertices.size();

// 	float y = 0.5f*height;
// 	float dTheta = 2.0f*XM_PI/sliceCount;

// 	// Duplicate cap ring _vertices because the texture coordinates and normals differ.
// 	for(uint32 i = 0; i <= sliceCount; ++i)
// 	{
// 		float x = topRadius*cosf(i*dTheta);
// 		float z = topRadius*sinf(i*dTheta);

// 		// Scale down by the height to try and make top cap texture coord area
// 		// proportional to base.
// 		float u = x/height + 0.5f;
// 		float v = z/height + 0.5f;

// 		meshData._vertices.push_back( Vertex(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
// 	}

// 	// Cap center vertex.
// 	meshData._vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

// 	// Index of center vertex.
// 	uint32 centerIndex = (uint32)meshData._vertices.size()-1;

// 	for(uint32 i = 0; i < sliceCount; ++i)
// 	{
// 		meshData._indices32.push_back(centerIndex);
// 		meshData._indices32.push_back(baseIndex + i+1);
// 		meshData._indices32.push_back(baseIndex + i);
// 	}
// }

// void GeometryGenerator::buildCylinderBottomCap(float bottomRadius, float topRadius, float height,
// 											   uint32 sliceCount, uint32 stackCount, MeshData& meshData)
// {
// 	// 
// 	// Build bottom cap.
// 	//

// 	uint32 baseIndex = (uint32)meshData._vertices.size();
// 	float y = -0.5f*height;

// 	// _vertices of ring
// 	float dTheta = 2.0f*XM_PI/sliceCount;
// 	for(uint32 i = 0; i <= sliceCount; ++i)
// 	{
// 		float x = bottomRadius*cosf(i*dTheta);
// 		float z = bottomRadius*sinf(i*dTheta);

// 		// Scale down by the height to try and make top cap texture coord area
// 		// proportional to base.
// 		float u = x/height + 0.5f;
// 		float v = z/height + 0.5f;

// 		meshData._vertices.push_back( Vertex(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
// 	}

// 	// Cap center vertex.
// 	meshData._vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

// 	// Cache the index of center vertex.
// 	uint32 centerIndex = (uint32)meshData._vertices.size()-1;

// 	for(uint32 i = 0; i < sliceCount; ++i)
// 	{
// 		meshData._indices32.push_back(centerIndex);
// 		meshData._indices32.push_back(baseIndex + i);
// 		meshData._indices32.push_back(baseIndex + i+1);
// 	}
// }

// GeometryGenerator::MeshData GeometryGenerator::createGrid(float width, float depth, uint32 m, uint32 n)
// {
//     MeshData meshData;

// 	uint32 vertexCount = m*n;
// 	uint32 faceCount   = (m-1)*(n-1)*2;

// 	//
// 	// Create the _vertices.
// 	//

// 	float halfWidth = 0.5f*width;
// 	float halfDepth = 0.5f*depth;

// 	float dx = width / (n-1);
// 	float dz = depth / (m-1);

// 	float du = 1.0f / (n-1);
// 	float dv = 1.0f / (m-1);

// 	meshData._vertices.resize(vertexCount);
// 	for(uint32 i = 0; i < m; ++i)
// 	{
// 		float z = halfDepth - i*dz;
// 		for(uint32 j = 0; j < n; ++j)
// 		{
// 			float x = -halfWidth + j*dx;

// 			meshData._vertices[i*n+j].Position = XMFLOAT3(x, 0.0f, z);
// 			meshData._vertices[i*n+j].Normal   = XMFLOAT3(0.0f, 1.0f, 0.0f);
// 			meshData._vertices[i*n+j].TangentU = XMFLOAT3(1.0f, 0.0f, 0.0f);

// 			// Stretch texture over grid.
// 			meshData._vertices[i*n+j].TexC.x = j*du;
// 			meshData._vertices[i*n+j].TexC.y = i*dv;
// 		}
// 	}
 
//     //
// 	// Create the indices.
// 	//

// 	meshData._indices32.resize(faceCount*3); // 3 indices per face

// 	// Iterate over each quad and compute indices.
// 	uint32 k = 0;
// 	for(uint32 i = 0; i < m-1; ++i)
// 	{
// 		for(uint32 j = 0; j < n-1; ++j)
// 		{
// 			meshData._indices32[k]   = i*n+j;
// 			meshData._indices32[k+1] = i*n+j+1;
// 			meshData._indices32[k+2] = (i+1)*n+j;

// 			meshData._indices32[k+3] = (i+1)*n+j;
// 			meshData._indices32[k+4] = i*n+j+1;
// 			meshData._indices32[k+5] = (i+1)*n+j+1;

// 			k += 6; // next quad
// 		}
// 	}

//     return meshData;
// }

// GeometryGenerator::MeshData GeometryGenerator::createQuad(float x, float y, float w, float h, float depth)
// {
//     MeshData meshData;

// 	meshData._vertices.resize(4);
// 	meshData._indices32.resize(6);

// 	// Position coordinates specified in NDC space.
// 	meshData._vertices[0] = Vertex(
//         x, y - h, depth,
// 		0.0f, 0.0f, -1.0f,
// 		1.0f, 0.0f, 0.0f,
// 		0.0f, 1.0f);

// 	meshData._vertices[1] = Vertex(
// 		x, y, depth,
// 		0.0f, 0.0f, -1.0f,
// 		1.0f, 0.0f, 0.0f,
// 		0.0f, 0.0f);

// 	meshData._vertices[2] = Vertex(
// 		x+w, y, depth,
// 		0.0f, 0.0f, -1.0f,
// 		1.0f, 0.0f, 0.0f,
// 		1.0f, 0.0f);

// 	meshData._vertices[3] = Vertex(
// 		x+w, y-h, depth,
// 		0.0f, 0.0f, -1.0f,
// 		1.0f, 0.0f, 0.0f,
// 		1.0f, 1.0f);

// 	meshData._indices32[0] = 0;
// 	meshData._indices32[1] = 1;
// 	meshData._indices32[2] = 2;

// 	meshData._indices32[3] = 0;
// 	meshData._indices32[4] = 2;
// 	meshData._indices32[5] = 3;

//     return meshData;
// }
