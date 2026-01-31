using Projects;

var builder = DistributedApplication.CreateBuilder(args);

var username = builder.AddParameter("postgres-username", "postgres");
var password = builder.AddParameter("postgres-password", "mxRUYSSc745J{vUbU6e}}C", secret: true);

var db = builder.AddPostgres("rathalos", username, password)
    .WithLifetime(ContainerLifetime.Persistent)
    .WithDataVolume()
    .AddDatabase("rathalos-world");

var world = builder.AddProject<Rathalos_ConsoleUI_World>("world")
    .WithExternalHttpEndpoints()
    .WithHttpHealthCheck("/health")
    .WithReference(db);

builder.Build().Run();
