using Projects;

var builder = DistributedApplication.CreateBuilder(args);

var username = builder.AddParameter("postgres-username", "postgres");
var password = builder.AddParameter("postgres-password", "mxRUYSSc745J{vUbU6e}}C", secret: true);

var db = builder.AddPostgres("rathalos", username, password)
    .WithEndpoint(name: "postgresendpoint", scheme: "tcp", port: 5432, targetPort: 5432, isProxied: false)
    .WithPgAdmin(pgAdmin => pgAdmin.WithContainerName("rathalos-db-admin").WithHostPort(8080).WithLifetime(ContainerLifetime.Persistent))
    .WithLifetime(ContainerLifetime.Persistent)
    .WithDataVolume()
    .AddDatabase("rathalos-world");


var world = builder.AddProject<Rathalos_ConsoleUI_World>("world")
    .WithExternalHttpEndpoints()
    .WithHttpHealthCheck("/health")
    .WithReference(db);

builder.Build().Run();
